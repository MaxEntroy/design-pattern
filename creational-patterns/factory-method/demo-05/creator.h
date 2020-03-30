#ifndef CREATOR_H_
#define CREATOR_H_

#include <memory>
#include "product.h"

namespace dp {

template<class TheProduct>
class Creator {
 public:
  Creator() {}
  typedef std::shared_ptr<Product> ProductPtr;

  static ProductPtr GetProduct() {
    return MakeProduct();
  }

 private:
  static ProductPtr MakeProduct() {
    return std::make_shared<TheProduct>();
  }
};

} // namespace dp

#endif // CREATOR_H_
