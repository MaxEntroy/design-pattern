#include "logging_acceptor.h"
#include "event_type.h"

namespace reactor {

Logging_Acceptor::Logging_Acceptor(const INET_Addr& addr)
    : acceptor_(addr) {
  // Register acceptor with the Initiation
  // Dispatcher, which "double dispatches"
  // the Logging_Acceptor::get_handle() method
  // to obtain the HANDLE.
  Initiation_Dispatcher::instance() ->
    register_event(this, Event_Type::ACCEPT_EVENT);
}

void Logging_Acceptor::handle_event(Event_Type et) {
  // Can only be called for an ACCEPT event
  assert(et == Event_Type::ACCEPT_EVENT);

  SOCK_Stream new_connection;

  // Accept the connection
  acceptor_.accept(new_connection);

  // Create a new Logging handler
  Logging_Handler* handler =
    new Logging_Handler(new_connection);
}

}  // namespace reactor
