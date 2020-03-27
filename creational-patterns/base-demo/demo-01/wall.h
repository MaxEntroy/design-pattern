#ifndef WALL_H_
#define WALL_H_

#include "map_site.h"

namespace dp {

class Wall : public MapSite {
 public:
  Wall() {}

  void Enter() override;
};

} // namespace dp

#endif // WALL_H_
