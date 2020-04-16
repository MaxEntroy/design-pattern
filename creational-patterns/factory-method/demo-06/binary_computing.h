#ifndef BINARY_COMPUTING_H_
#define BINARY_COMPUTING_H_

namespace dp {

class BinaryComputing {
 public:
  BinaryComputing() : left_(0), right_(0) {}
  BinaryComputing(int l, int r) : left_(l), right_(r) {}
  virtual ~BinaryComputing() {}

  virtual int DoComputing() const = 0;

 protected:
  int left_;
  int right_;
};

} // namespace dp

#endif // BINARY_COMPUTING
