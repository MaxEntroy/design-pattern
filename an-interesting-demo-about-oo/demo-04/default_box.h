#ifndef DEFAULT_BOX_H_
#define DEFAULT_BOX_H_

class DefaultBox {
 public:
  DefaultBox() {}

  std::string GetMessage() const {
    return "This is not a box.";
  }
};

#endif
