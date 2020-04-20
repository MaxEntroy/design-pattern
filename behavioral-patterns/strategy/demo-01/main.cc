#include "context.h"
#include "circle_strategy.h"
#include "triangle_strategy.h"
#include "rectangle_strategy.h"

int main(void) {
  Context ctx(new CircleStrategy(1.0));
  ctx.ContextInterface();

  Context ctx2(new TriangleStrategy(1.0, 1.0));
  ctx2.ContextInterface();

  Context ctx3(new RectangleStrategy(1.0, 1.0));
  ctx3.ContextInterface();

  return 0;
}
