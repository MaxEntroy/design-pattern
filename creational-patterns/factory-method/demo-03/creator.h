#ifndef CREATOR_H_
#define CREATOR_H_

#include <memory>
#include "product.h"

namespace dp {

class Creator {
 public:
  virtual ~Creator() {}
  typedef std::shared_ptr<Product> ProductPtr;

  ProductPtr GetProduct() {
    if(product_ptr_)
      return product_ptr_;

    product_ptr_ = MakeProduct();
    return product_ptr_;
  }

 private:
  virtual ProductPtr MakeProduct() = 0;

 private:
  ProductPtr product_ptr_;
};

} // namespace dp

#endif // CREATOR_H_
