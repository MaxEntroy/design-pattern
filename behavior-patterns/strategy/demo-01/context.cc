#include "context.h"

#include <iostream>

void Context::ContextInterface() {
  std::cout << strategy_->NameOf() << std::endl;
  std::cout << "Area is " << strategy_->Area() << std::endl;
}
