#ifndef MAZE_H_
#define MAZE_H_

#include "room.h"

namespace dp {

class Maze {
 public:
  typedef std::shared_ptr<Room> RoomPtr;

 public:
  Maze() {}

 public:
  void AddRoom(RoomPtr p) {
    rooms_.push_back(p);
  }

  RoomPtr RoomNo(int rn) const {
    return rooms_[rn];
  }

 private:
  std::vector<RoomPtr> rooms_;
};

} // namespace dp

#endif // MAZE_H_
