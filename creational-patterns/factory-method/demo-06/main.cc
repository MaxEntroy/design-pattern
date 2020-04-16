#include <iostream>

#include "add_computing.h"
#include "computing_factory.h"
#include "minus_computing.h"

using namespace dp;

int main() {
  std::shared_ptr<AddComputing> add_ptr = ComputingFactory<AddComputing>::GetComputing(3, 4);
  int ret = add_ptr->DoComputing();
  std::cout << ret << std::endl;

  std::shared_ptr<MinusComputing> minus_ptr = ComputingFactory<MinusComputing>::GetComputing(3, 4);
  ret = minus_ptr->DoComputing();
  std::cout << ret << std::endl;

  return 0;
}
