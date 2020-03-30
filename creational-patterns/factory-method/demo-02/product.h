#ifndef PRODUCT_H_
#define PRODUCT_H_

namespace dp {

class Product {
 public:
  virtual ~Product() {}

 public:
  virtual void DoSomething() = 0;
};

} // namespace dp

#endif // PRODUCT_H_
