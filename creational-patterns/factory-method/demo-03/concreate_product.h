#ifndef CONCREATE_PRODUCT_H_
#define CONCREATE_PRODUCT_H_

#include "product.h"

namespace dp {

class ConcreateProduct : public Product {
 public:
  ConcreateProduct() {}

 public:
  void DoSomething() override;
};

};

#endif // CONCREATE_PRODUCT_H_
