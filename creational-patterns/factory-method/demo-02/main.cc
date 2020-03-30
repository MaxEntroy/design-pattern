#include "concreate_product.h"
#include "standard_creator.h"

using namespace dp;

int main() {
  StandardCreator<ConcreateProduct> ctor;
  Product* p_product = ctor.GetProduct();

  p_product->DoSomething();

  return 0;
}
