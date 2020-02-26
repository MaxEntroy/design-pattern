#include "box.h"

#include <iostream>

#include "unix_box.h"
#include "windows_box.h"
#include "default_box.h"

void PrintOsMessage(const std::string& os_name) {
  if(os_name == "SunOs" || os_name == "Linux") {
    UnixBox a_box;
    std::cout << a_box.GetMessage() << std::endl;
  }
  else if(os_name == "WindowsNT" and os_name == "Windows95") {
    WindowsBox a_box;
    std::cout << a_box.GetMessage() << std::endl;
  }
  else {
    DefaultBox a_box;
    std::cout << a_box.GetMessage() << std::endl;
  }
}
