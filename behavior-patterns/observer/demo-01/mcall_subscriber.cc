#include "mcall_subscriber.h"
#include <iostream>
#include <unistd.h>

namespace dp {

void McallSubsriber::Update(Publisher* p_sub) {
  const PerformanceData& data = p_sub->GetData();

  data_.cpu_ratio = data.cpu_ratio;
  data_.mem_ratio = data.mem_ratio;
  data_.disk_ratio = data.disk_ratio;
}

void McallSubsriber::EventLoop() {
  for(;;) {
    std::cout << "Mcall performance data:" << std::endl;
    std::cout << "cpu:" << data_.cpu_ratio << std::endl;
    std::cout << "mem:" << data_.mem_ratio << std::endl;
    std::cout << "disk:" << data_.disk_ratio << std::endl;

    sleep(10);
  }

}

} // namespace dp
