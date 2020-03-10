#include "circle_strategy.h"

#include <math.h>

#include <iostream>

static const double kPI = atan(1.0) * 4;

std::string CircleStrategy::NameOf() const {
  return "This is a circle.";
}

double CircleStrategy::Area() const {
  return kPI * radius_ * radius_;
}
