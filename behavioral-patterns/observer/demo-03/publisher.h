#ifndef PUBLISHER_H_
#define PUBLISHER_H_

#include <list>

#include "subscriber.h"

namespace dp {

class Publisher {
 public:
  virtual ~Publisher() = default;

  void Attach(Subscriber*);
  void Detach(Subscriber*);

  void OnPublish();

 private:
  virtual void SetState() = 0;
  void Notify();

 private:
  std::list<Subscriber*> subscriber_ptr_list_;
};

} // namespace dp

#endif // PUBLISHER_H_
