#include "door.h"
#include "maze_creator.h"
#include "wall.h"

namespace dp {

MazeCreator::MazePtr MazeCreator::GetMaze() {
  MazePtr maze_ptr = MakeMaze();

  RoomPtr rm1_ptr = MakeRoom(1);
  RoomPtr rm2_ptr = MakeRoom(2);

  DoorPtr door_ptr = MakeDoor(rm1_ptr, rm2_ptr);

  rm1_ptr->SetSide(kNorth, MakeWall());
  rm1_ptr->SetSide(kSouth, MakeWall());
  rm1_ptr->SetSide(kEast, door_ptr);
  rm1_ptr->SetSide(kWest, MakeWall());

  rm2_ptr->SetSide(kNorth, MakeWall());
  rm2_ptr->SetSide(kSouth, MakeWall());
  rm2_ptr->SetSide(kEast, MakeWall());
  rm2_ptr->SetSide(kWest, door_ptr);

  maze_ptr->AddRoom(rm1_ptr);
  maze_ptr->AddRoom(rm2_ptr);

  return maze_ptr;
}

MazeCreator::MazePtr MazeCreator::MakeMaze() {
  return std::make_shared<Maze>();
}

MazeCreator::RoomPtr MazeCreator::MakeRoom(int room_no) {
  return std::make_shared<Room>(room_no);
}

MazeCreator::DoorPtr MazeCreator::MakeDoor(RoomPtr rm1_ptr, RoomPtr rm2_ptr) {
  return std::make_shared<Door>(rm1_ptr, rm2_ptr);
}

MazeCreator::WallPtr MazeCreator::MakeWall() {
  return std::make_shared<Wall>();
}

} // namespace dp
