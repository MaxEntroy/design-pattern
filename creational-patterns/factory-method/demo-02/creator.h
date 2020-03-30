#ifndef CREATOR_H_
#define CREATOR_H_

#include "product.h"

namespace dp {

class Creator {
 public:
  Creator() : p_product_(nullptr) {}
  virtual ~Creator() {}

  Product* GetProduct() {
    if(p_product_)
      return p_product_;

    p_product_ = MakeProduct();
    return p_product_;
  }

 private:
  virtual Product* MakeProduct() = 0;

 private:
  Product* p_product_;
};

} // namespace dp

#endif // CREATOR_H_
