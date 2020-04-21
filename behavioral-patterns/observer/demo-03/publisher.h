#ifndef PUBLISHER_H_
#define PUBLISHER_H_

#include <list>

#include "subscriber.h"

namespace dp {

class Publisher {
 public:
  virtual ~Publisher() {}

  void Attach(Subscriber*);
  void Detach(Subscriber*);

  void OnPublish();

 private:
  void Notify();
  virtual void SetState() = 0;

 private:
  std::list<Subscriber*> subscriber_ptr_list_;
};

} // namespace dp

#endif // PUBLISHER_H_
