#ifndef CIRCLE_STRATEGY_H_
#define CIRCLE_STRATEGY_H_

#include "strategy.h"

class CircleStrategy : public Strategy {
 public:
  CircleStrategy() {}
  CircleStrategy(double r) : radius_(r) {}

 public:
  std::string NameOf() const override;
  double Area() const override;

 private:
  double radius_;
};

#endif
