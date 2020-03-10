#ifndef TRIANGLE_STRATEGY_H_
#define TRIANGLE_STRATEGY_H_

#include "strategy.h"

class TriangleStrategy : public Strategy {
 public:
   TriangleStrategy() {}
   TriangleStrategy(double w, double h) : width_(w), height_(h) {}

 public:
   std::string NameOf() const override;
   double Area() const override;

 private:
  double width_;
  double height_;
};

#endif
