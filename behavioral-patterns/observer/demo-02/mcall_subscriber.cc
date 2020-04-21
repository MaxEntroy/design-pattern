#include "mcall_subscriber.h"

#include <iostream>

namespace dp {

void McallSubscriber::Update() {
  app_data_.cpu_ratio = p_per_pub_->GetCpu();
  app_data_.mem_ratio = p_per_pub_->GetMem();
  app_data_.disk_ratio = p_per_pub_->GetDisk();
}

void McallSubscriber::ShowAppData() const {
  std::cout << "Mcall Report:" << std::endl;
  std::cout << "cpu : " << app_data_.cpu_ratio << std::endl;
  std::cout << "mem : " << app_data_.mem_ratio << std::endl;
  std::cout << "disk: " << app_data_.disk_ratio << std::endl;
}

} // namespace dp
