#ifndef REACTOR_EVENT_HANDLER_H_
#define REACTOR_EVENT_HANDLER_H_

namespace reactor {

class Event_Handler {
  // Abstract base class that serve as the
  // target of the Initiation_Dispatcher
 public:
  virtual ~Event_Handler() = default;

  // Hook method that is called back by the
  // Initiation_Dispatcher to handle events
  virtual void handle_event(Event_Type et) = 0;

  // Hook method that returns the underlying
  // I/O handle
  virtual Handle get_handle() const = 0;
};

}  // namespace reactor

#endif
