#ifndef ADD_COMPUTING_H_
#define ADD_COMPUTING_H_

#include "binary_computing.h"

namespace dp {

class AddComputing : public BinaryComputing {
 public:
  AddComputing() : BinaryComputing() {}
  AddComputing(int l, int r) : BinaryComputing(l, r) {}

  int DoComputing() const override;

};

} // namespace dp

#endif // ADD_COMPUTING_H_
