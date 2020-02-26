#ifndef UNIX_BOX_H_
#define UNIX_BOX_H_

class UnixBox {
 public:
  UnixBox() {}

  std::string GetMessage() const {
    return "This is a Unix box and therefore good.";
  }
};

#endif
