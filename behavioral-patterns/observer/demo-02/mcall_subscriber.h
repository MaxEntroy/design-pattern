#ifndef MCALL_SUBSCRIBER_H_
#define MCALL_SUBSCRIBER_H_

#include "app_data.h"
#include "performance_publisher.h"
#include "subscriber.h"

namespace dp {

class McallSubscriber : public Subscriber {
 public:
  McallSubscriber() : p_per_pub_(nullptr) {}
  explicit McallSubscriber(PerformancePublisher* p) : p_per_pub_(p) {
    p_per_pub_->Attach(this);
  }
  ~McallSubscriber() {
    p_per_pub_->Detach(this);
  }

 public:
  void Update() override;

  void ShowAppData() const;
 private:
  ApplicationData app_data_;
  PerformancePublisher* p_per_pub_;
};



} // namespace dp

#endif // MCALL_SUBSCRIBER_H_
