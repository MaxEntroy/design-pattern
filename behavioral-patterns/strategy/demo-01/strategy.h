#ifndef STRATEGY_H_
#define STRATEGY_H_

#include <string>

class Strategy {
 public:
  virtual ~Strategy() {}

 public:
  virtual std::string NameOf() const = 0;
  virtual double Area() const = 0;

};

#endif
