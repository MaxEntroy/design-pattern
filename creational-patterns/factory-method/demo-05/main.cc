#include "concreate_product.h"
#include "creator.h"

using namespace dp;

int main() {
  std::shared_ptr<Product> product_ptr = Creator<ConcreateProduct>::GetProduct();
  product_ptr->DoSomething();

  return 0;
}
