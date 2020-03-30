#ifndef BOMBED_MAZE_CREATOR_H_
#define BOMBED_MAZE_CREATOR_H_

#include "maze_creator.h"

namespace dp {

class BombedMazeCreator : public MazeCreator {
 public:
  BombedMazeCreator() : MazeCreator() {}

 private:
  DoorPtr MakeDoor(RoomPtr rm1_ptr, RoomPtr rm2_ptr) override;
};

} // namespace dp

#endif // BOMBED_MAZE_CREATOR_H_
