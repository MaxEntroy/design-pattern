#ifndef MAZE_CREATOR_H_
#define MAZE_CREATOR_H_

#include "door.h"
#include "maze.h"
#include "wall.h"

namespace dp {

class MazeCreator {
 public:
  MazeCreator() {}
  virtual ~MazeCreator() {}

 public:
  typedef std::shared_ptr<Maze> MazePtr;
  typedef std::shared_ptr<Room> RoomPtr;
  typedef std::shared_ptr<Door> DoorPtr;
  typedef std::shared_ptr<Wall> WallPtr;

  MazePtr GetMaze();

 private:
  virtual MazePtr MakeMaze();
  virtual RoomPtr MakeRoom(int room_no);
  virtual DoorPtr MakeDoor(RoomPtr rm1_ptr, RoomPtr rm2_ptr);
  virtual WallPtr MakeWall();
};

} // namespace dp

#endif // MAZE_CREATOR_H_
