#ifndef MCALL_SUBSCRIBER_H_
#define MCALL_SUBSCRIBER_H_

#include "data.h"
#include "subscriber.h"

namespace dp {

class McallSubsriber : public Subscriber {
 public:
  void Update(Publisher* p_pub) override;

  void EventLoop();

 private:
  PerformanceData data_;
};

} // namespace dp

#endif // MCALL_SUBSCRIBER_H_
