#include "bombed_door.h"
#include "bombed_maze_creator.h"

namespace dp {

MazeCreator::DoorPtr BombedMazeCreator::MakeDoor(MazeCreator::RoomPtr rm1_ptr, MazeCreator::RoomPtr rm2_ptr) {
  return std::make_shared<BombedDoor>(rm1_ptr, rm2_ptr);
}

} // namespace dp
