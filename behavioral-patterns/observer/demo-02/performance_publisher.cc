#include "performance_publisher.h"

namespace dp {

void PerformancePublisher::SetState() {
  app_data_.cpu_ratio += 0.01;
  app_data_.mem_ratio += 0.02;
  app_data_.disk_ratio += 0.03;
}

} // namespace dp
