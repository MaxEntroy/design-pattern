#ifndef CONCREATE_CREATOR_H_
#define CONCREATE_CREATOR_H_

#include "creator.h"

namespace dp {

class ConcreateCreator : public Creator {
 public:
  ConcreateCreator() : Creator() {}

 private:
  Product* MakeProduct() override;
};

} // namespace dp

#endif // CONCREATE_CREATOR_H_
