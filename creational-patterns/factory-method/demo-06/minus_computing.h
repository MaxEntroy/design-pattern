#ifndef MINUS_COMPUTING_H_
#define MINUS_COMPUTING_H_

#include "binary_computing.h"

namespace dp {

class MinusComputing : public BinaryComputing {
 public:
  MinusComputing() : BinaryComputing() {}
  MinusComputing(int l, int r) : BinaryComputing(l, r) {}

  int DoComputing() const override;
};

} // namespace dp

#endif // MINUS_COMPUTING_H_
