#ifndef PERFORMANCE_PUBLISHER_H_
#define PERFORMANCE_PUBLISHER_H_

#include <iostream>

#include "app_data.h"
#include "publisher.h"

namespace dp {

class PerformancePublisher : public Publisher {
 public:
  ~PerformancePublisher() {std::cout << "~PerformancePublisher() called.\n";}
  void SetState() override;

  double GetCpu() const {return app_data_.cpu_ratio;}
  double GetMem() const {return app_data_.mem_ratio;}
  double GetDisk() const {return app_data_.disk_ratio;}

 private:
  ApplicationData app_data_;
};

} // namespace dp

#endif // PERFORMANCE_PUBLISHER_H_
