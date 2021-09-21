#ifndef REACTOR_EVENT_TYPE_H_
#define REACTOR_EVENT_TYPE_H_

namespace {

enum class Event_Type {
  // Types of events handled by the
  // Initiation_Dispatcher
  //
  // These values are powers of two so
  // their bits can be efficiently ''or''
  // together to form composive valus
  ACCEPT_EVENT = 01,
  READ_EVENT = 02,
  WRITE_EVENT = 04,
  TIMEOUT_EVENT = 010,
  SIGNAL_EVENT = 020,
  CLOSE_EVENT = 040
};

}  // namespace reactor

#endif  // REACTOR_EVENT_TYPE_H_
