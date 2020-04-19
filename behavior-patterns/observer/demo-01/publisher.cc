#include "publisher.h"

namespace dp {

void Publisher::Attach(Subscriber* p_ob) {
  ob_list_.push_back(p_ob);
}

void Publisher::Detach(Subscriber* p_ob) {
  ob_list_.remove(p_ob);
}

void Publisher::Notify() {
  for(auto p_ob : ob_list_) {
    p_ob->Update(this);
  }
}

} // namespace dp
