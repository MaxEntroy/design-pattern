#include "singleton.h"

int main(void) {
  Singleton& s = Singleton::GetInstance();
  return 0;
}
