#include "door.h"
#include "maze_game.h"
#include "wall.h"

namespace dp {

std::shared_ptr<Maze> MazeGame::CreateMaze() const {
  std::shared_ptr<Maze> maze_ptr = std::make_shared<Maze>();

  std::shared_ptr<Room> rm1_ptr = std::make_shared<Room>(1);
  std::shared_ptr<Room> rm2_ptr = std::make_shared<Room>(2);

  std::shared_ptr<Door> door_ptr = std::make_shared<Door>(rm1_ptr, rm2_ptr);

  rm1_ptr->SetSide(kNorth, std::make_shared<Wall>());
  rm1_ptr->SetSide(kSouth, std::make_shared<Wall>());
  rm1_ptr->SetSide(kEast, door_ptr);
  rm1_ptr->SetSide(kWest, std::make_shared<Wall>());

  rm2_ptr->SetSide(kNorth, std::make_shared<Wall>());
  rm2_ptr->SetSide(kSouth, std::make_shared<Wall>());
  rm2_ptr->SetSide(kEast, std::make_shared<Wall>());
  rm2_ptr->SetSide(kWest, door_ptr);

  maze_ptr->AddRoom(rm1_ptr);
  maze_ptr->AddRoom(rm2_ptr);

  return maze_ptr;
}

} // namespace dp
