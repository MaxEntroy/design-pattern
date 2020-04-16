#ifndef COMPUTING_FACTORY_H_
#define COMPUTING_FACTORY_H_

#include <memory>

namespace dp {

template<class TheComputing>
class ComputingFactory {
 public:
  typedef std::shared_ptr<TheComputing> ComputingPtr;
  ComputingFactory() {}

  static ComputingPtr GetComputing(int left, int right) {
    return MakeComputing(left, right);
  }

 private:
  static ComputingPtr MakeComputing(int left, int right) {
    return std::make_shared<TheComputing>(left, right);
  }

};

} // namespace dp

#endif // COMPUTING_FACTORY_H_
