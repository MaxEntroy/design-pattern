#include "publisher.h"

namespace dp {

void Publisher::Attach(Subscriber* p_sub) {
  p_subscriber_list_.push_back(p_sub);
}

void Publisher::Detach(Subscriber* p_sub) {
  p_subscriber_list_.remove(p_sub);
}

void Publisher::OnPublish() {
  SetState();

  Notify();
}

void Publisher::Notify() {
  for(auto p_sub : p_subscriber_list_) {
    p_sub->Update();
  }
}

} // namespace dp
