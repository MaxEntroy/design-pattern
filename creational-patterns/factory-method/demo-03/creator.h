#ifndef CREATOR_H_
#define CREATOR_H_

#include <memory>
#include "product.h"

namespace dp {

class Creator {
 public:
  Creator() : p_product_(nullptr) {}
  virtual ~Creator() {}
  typedef std::shared_ptr<Product> ProductPtr;

  ProductPtr GetProduct() {
    if(p_product_)
      return p_product_;

    p_product_ = MakeProduct();
    return p_product_;
  }

 private:
  virtual ProductPtr MakeProduct() = 0;

 private:
  ProductPtr p_product_;
};

} // namespace dp

#endif // CREATOR_H_
