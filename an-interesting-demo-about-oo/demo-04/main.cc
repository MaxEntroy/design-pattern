#include "box.h"
#include "common.h"
#include "util.h"

int main(void) {

  std::map<std::string, std::unique_ptr<Box>> mapping;
  RegisterBox(&mapping);

  OsProperty os;
  std::string os_name = os.GetOsName();

  PrintOsMessage(os_name, mapping);

  return 0;
}
