#ifndef WINDOWS_BOX_H_
#define WINDOWS_BOX_H_

class WindowsBox {
 public:
  WindowsBox() {}

  std::string GetMessage() const {
    return "This is a Windows box and therefore bad.";
  }
};

#endif
