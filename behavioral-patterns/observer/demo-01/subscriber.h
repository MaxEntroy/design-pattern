#ifndef SUBSCRIBER_H_
#define SUBSCRIBER_H_

namespace dp {

class Publisher;

class Subscriber {
 public:
  virtual ~Subscriber() {}

 public:
  virtual void Update(Publisher*) = 0;
};

} // namespace dp

#endif // SUBSCRIBER_H_
