#ifndef STANDARD_CREATOR_H_
#define STANDARD_CREATOR_H_

#include "creator.h"

namespace dp {

template<class TheProduct>
class StandardCreator : public Creator {
 private:
  ProductPtr MakeProduct() {
    return std::make_shared<TheProduct>();
  }
};

} // namespace dp

#endif // STANDARD_CREATOR_H_
