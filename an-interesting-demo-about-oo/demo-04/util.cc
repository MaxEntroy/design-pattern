#include "util.h"

#include <iostream>

#include "box.h"
#include "unix_box.h"
#include "windows_box.h"
#include "default_box.h"

void RegisterBox(std::map<std::string, std::unique_ptr<Box>>* p_mapping) {
  (*p_mapping)["SunOs"] = std::make_unique<UnixBox>();
  (*p_mapping)["Linux"] = std::make_unique<UnixBox>();

  (*p_mapping)["WindowsNT"] = std::make_unique<WindowsBox>();
  (*p_mapping)["Windows95"] = std::make_unique<WindowsBox>();

  (*p_mapping)["Default"] = std::make_unique<DefaultBox>();
}

void PrintOsMessage(const std::string& os_name,
                    const std::map<std::string, std::unique_ptr<Box>>& mapping) {
  if(mapping.find(os_name) != mapping.end()) {
    std::cout << mapping[os_name]->OnMessage() << std::endl;
  }
  else {
    std::cout << mapping["Defalut"]->Onmessage() << std::endl;
  }
}
