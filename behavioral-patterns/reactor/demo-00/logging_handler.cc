#include "logging_handler.h"

namespace reactor {

Logging_Handler::Logging_Handler(SOCK_Stream& cs)
    : peer_stream_(cs) {
  // Register with the dispatcher for
  // READ events.
      Initiation_Dispatcher::instance() ->
        register_handler(this, Event_Type::READ_EVENT);
}

Logging_Handler::handle_event(Event_Type et) {
  if (et == Event_Type::READ_EVENT) {
    Log_Record log_record;

    peer_stream_.recv((void *) log_record, sizeof(log_record));

    // Write logging record to standard output
    log_record.write(STDOUT);
  } else if (et == Event_Type::Close_Event) {
    delete (void *) this;
  }
}

}  // namespace reactor
