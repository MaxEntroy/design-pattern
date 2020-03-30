#include "concreate_creator.h"
using namespace dp;

int main() {
  ConcreateCreator ctor;
  Product* p_product = ctor.GetProduct();

  p_product->DoSomething();

  return 0;
}
