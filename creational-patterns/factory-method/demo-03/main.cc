#include "concreate_product.h"
#include "standard_creator.h"

using namespace dp;

int main() {
  std::shared_ptr<Creator> ctor_ptr = std::make_shared< StandardCreator<ConcreateProduct> >();
  std::shared_ptr<Product> product_ptr = ctor_ptr->GetProduct();
  product_ptr->DoSomething();

  return 0;
}
