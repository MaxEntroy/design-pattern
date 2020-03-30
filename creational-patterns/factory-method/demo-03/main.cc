#include "concreate_product.h"
#include "standard_creator.h"

using namespace dp;

int main() {
  StandardCreator<ConcreateProduct> ctor;
  Creator::ProductPtr product_ptr = ctor.GetProduct();

  product_ptr->DoSomething();

  return 0;
}
