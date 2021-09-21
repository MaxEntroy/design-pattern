#ifndef REACTOR_LOGGING_ACCEPTOR_H_
#define REACTOR_LOGGING_ACCEPTOR_H_

#include "event_handler.h"

namespace reactor {

class Logging_Acceptor : public Event_Handler {
// Handle client connection requests
 public:
  // Initialize the acceptor endpoint and
  // register with the Initiation_Dispatcher
  Logging_Acceptor(const INET_Addr& addr);

  // Factory method that accpets a new
  // sock_stream connection and creates a
  // Logging_Handler object to handle logging
  // records sent using the connection.
  void handle_event(Event_Type et) override;

  // Get the I/O handle (called by the
  // Initiation_Dispatcher when
  // Logging_Acceptor is registered).
  Handle get_handle() const override {
    return acceptor_.get_handle();
  }

 private:
  // Socket factory that accepts client
  // connections
  SOCK_Acceptor acceptor_;
};

}  // namespace reactor

#endif // REACTOR_LOGGING_ACCEPTOR_H_
