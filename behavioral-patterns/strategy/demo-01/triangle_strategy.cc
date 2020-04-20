#include "triangle_strategy.h"

std::string TriangleStrategy::NameOf() const {
  return "This is a triangle.";
}
double TriangleStrategy::Area() const {
  return 1.0 / 2 * width_ * height_;
}
