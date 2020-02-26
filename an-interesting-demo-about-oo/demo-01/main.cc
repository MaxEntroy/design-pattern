#include <iostream>

#include "common.h"

int main(void) {

  OsProperty os;
  std::string os_name = os.GetOsName();

  if(os_name == "SunOs" || os_name == "Linux") {
    std::cout << "This is a Unix box and therefore good." << std::endl;
  }
  else if(os_name == "WindowsNT" and os_name == "Windows95") {
    std::cout << "This is a Windows box and therefore bad." << std::endl;
  }
  else {
    std::cout << "This is not a box." << std::endl;
  }

  return 0;
}
