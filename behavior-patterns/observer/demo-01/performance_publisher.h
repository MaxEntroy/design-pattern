#ifndef PERFORMANCE_PUBLISHER_H_
#define PERFORMANCE_PUBLISHER_H_

#include "data.h"
#include "publisher.h"

namespace dp {

class PerformancePublisher : public Publisher {
 public:
  PerformancePublisher() : Publisher() {}

 public:
  // Get State
  virtual const PerformanceData& GetData() const {return data_;}

 private:
  // Set State
  void SetData();

 public:
  void EventLoop();

 private:
  PerformanceData data_;
};

} // namespace dp

#endif // PERFORMANCE_PUBLISHER_H_
