#ifndef SUBSCRIBER_H_
#define SUBSCRIBER_H_

namespace dp {

class Subscriber {
 public:
  virtual ~Subscriber() {}

  virtual void Update() = 0;
};

} // namespace dp

#endif // SUBSCRIBER_H_
