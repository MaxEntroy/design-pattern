#ifndef REACTOR_LOGGING_HANDLER_H_
#define REACTOR_LOGGING_HANDLER_H_

#include "event_handler.h"

namespace reactor {

class Logging_Handler : public Event_Handler {
// Receive and process logging records
// sent by a client application
 public:
  // Initialize the client stream
  Logging_Handler(SOCK_Stream& cs);

  // Hook method that handles the reception
  // of logging records form clients
  void handle_event(Event_Type et) override;

  //  Get the I/O handle(called by the
  //  Initiation_Dispatcher when
  //  Logging_Handler is registered)
  Handle get_handle() const override {
    return peer_stream_.get_handle();
  }

 private:
  // Receive logging records form a client
  SOCK_Stream peer_stream_;
};

}  // namespace reactor

#endif // REACTOR_LOGGING_HANDLER_H_
