#ifndef COMMON_H_
#define COMMON_H_

#include <string>

class OsProperty {
 public:
  OsProperty() {}

  std::string GetOsName() const {
    return "Linux";
  }
};

#endif
