#include "box.h"
#include "common.h"

int main(void) {

  OsProperty os;
  std::string os_name = os.GetOsName();

  PrintOsMessage(os_name);

  return 0;
}
