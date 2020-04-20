#include "rectangle_strategy.h"

std::string RectangleStrategy::NameOf() const {
  return "This is a rectangle.";
}
double RectangleStrategy::Area() const {
  return width_ * length_;
}
