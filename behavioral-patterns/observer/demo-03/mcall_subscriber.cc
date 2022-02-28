#include "mcall_subscriber.h"

#include <iostream>

namespace dp {
McallSubscriber::McallSubscriber(PerPubPtr ptr) : per_pub_ptr_(ptr) {
    per_pub_ptr_->Attach(this);
}

McallSubscriber::~McallSubscriber() {
    per_pub_ptr_->Detach(this);
}

void McallSubscriber::Update() {
  app_data_.cpu_ratio = per_pub_ptr_->GetCpu();
  app_data_.mem_ratio = per_pub_ptr_->GetMem();
  app_data_.disk_ratio = per_pub_ptr_->GetDisk();
}

void McallSubscriber::ShowAppData() const {
  std::cout << "Mcall Report:" << std::endl;
  std::cout << "cpu : " << app_data_.cpu_ratio << std::endl;
  std::cout << "mem : " << app_data_.mem_ratio << std::endl;
  std::cout << "disk: " << app_data_.disk_ratio << std::endl;
}

} // namespace dp
