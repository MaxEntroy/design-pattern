#ifndef PUBLISHER_H_
#define PUBLISHER_H_

#include <list>

#include "subscriber.h"

namespace dp {

class Publisher {
 public:
  virtual ~Publisher() {}

 public:
  void Attach(Subscriber*);
  void Detach(Subscriber*);
  void Notify();

 protected:
  Publisher() {}

 private:
  std::list<Subscriber*> ob_list_;
};

} // namespace dp

#endif // PUBLISHER_H_
