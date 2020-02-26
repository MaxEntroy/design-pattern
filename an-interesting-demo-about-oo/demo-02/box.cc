#include "box.h"

#include <iostream>

void PrintOsMessage(const std::string& os_name) {
  if(os_name == "SunOs" || os_name == "Linux") {
    std::cout << UnixBox() << std::endl;
  }
  else if(os_name == "WindowsNT" and os_name == "Windows95") {
    std::cout << WindowsBox() << std::endl;
  }
  else {
    std::cout << DefaultBox() << std::endl;
  }
}

std::string UnixBox() {
  return "This is a Unix box and therefore good.";
}

std::string WindowsBox() {
  return "This is a Windows box and therefore bad.";
}

std::string DefaultBox() {
  return "This is not a box.";
}
