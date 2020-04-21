#ifndef PUBLISHER_H_
#define PUBLISHER_H_

#include <list>
#include <memory>

#include "subscriber.h"

namespace dp {

class Publisher {
 public:
  typedef std::shared_ptr<Subscriber> SubSPtr;
  typedef std::weak_ptr<Subscriber> SubWPtr;
  virtual ~Publisher() {}

  void Attach(SubWPtr);

  void OnPublish();

 private:
  void Notify();
  virtual void SetState() = 0;

 private:
  std::list<SubWPtr> subscriber_ptr_list_;
};

} // namespace dp

#endif // PUBLISHER_H_
