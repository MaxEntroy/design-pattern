#include "publisher.h"

namespace dp {

void Publisher::Attach(Subscriber* ptr) {
  subscriber_ptr_list_.push_back(ptr);
}

void Publisher::Detach(Subscriber* ptr) {
  subscriber_ptr_list_.remove(ptr);
}

void Publisher::OnPublish() {
  SetState();
  Notify();
}

void Publisher::Notify() {
  for(auto& ptr : subscriber_ptr_list_) {
    ptr->Update();
  }
}

} // namespace dp
