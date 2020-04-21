#include "publisher.h"

namespace dp {

void Publisher::Attach(SubWPtr ptr) {
  subscriber_ptr_list_.push_back(ptr);
}

void Publisher::OnPublish() {
  SetState();

  Notify();
}

void Publisher::Notify() {
  for(auto ptr : subscriber_ptr_list_) {
    if (SubSPtr sptr = ptr.lock()) {
      sptr->Update();
    }
  }
}

} // namespace dp
