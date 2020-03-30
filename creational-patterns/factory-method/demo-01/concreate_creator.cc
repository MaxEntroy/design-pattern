#include "concreate_creator.h"
#include "concreate_product.h"

namespace dp {

Product* ConcreateCreator::MakeProduct() {
  return new ConcreateProduct();
}

};
