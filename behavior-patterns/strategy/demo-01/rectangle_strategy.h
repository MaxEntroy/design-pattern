#ifndef RECTANGLE_STRATEGY_H_
#define RECTANGLE_STRATEGY_H_

#include "strategy.h"

class RectangleStrategy : public Strategy {
 public:
   RectangleStrategy() {}
   RectangleStrategy(double w, double l) : width_(w), length_(l) {}

 public:
  std::string NameOf() const override;
  double Area() const override;

 private:
  double width_;
  double length_;
};

#endif
