#ifndef MCALL_SUBSCRIBER_H_
#define MCALL_SUBSCRIBER_H_

#include <iostream>

#include "app_data.h"
#include "performance_publisher.h"
#include "subscriber.h"

namespace dp {

class McallSubscriber : public Subscriber {
 public:
  typedef std::shared_ptr<PerformancePublisher> PerPubPtr;
  explicit McallSubscriber(PerPubPtr ptr) : per_pub_ptr_(ptr) {}
  ~McallSubscriber() {std::cout << "~McallSubscriber() called.\n";}

 public:
  void Update() override;

  void ShowAppData() const;
 private:
  ApplicationData app_data_;
  PerPubPtr per_pub_ptr_;
};



} // namespace dp

#endif // MCALL_SUBSCRIBER_H_
