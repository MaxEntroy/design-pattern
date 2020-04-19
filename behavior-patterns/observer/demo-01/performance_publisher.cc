#include "performance_publisher.h"

#include <unistd.h>

namespace dp {

// Set State
// 1. Update state form external/upstream data
// 2. How to set state is not the main promblem of the pattern
// 3. Mock set state by increament
void PerformancePublisher::SetData() {
  data_.cpu_ratio += 0.02;
  data_.mem_ratio += 0.01;
  data_.disk_ratio += 0.03;
}

void PerformancePublisher::EventLoop() {
  for(;;) {
    SetData();

    Notify();

    sleep(60);
  }
}

} // namespace dp
