#ifndef DOOR_H_
#define DOOR_H_

#include "map_site.h"
#include "room.h"

namespace dp {

class Door : public MapSite {
 public:
  typedef std::shared_ptr<Room> RoomPtr;

 public:
  Door() {}
  Door(RoomPtr r1, RoomPtr r2) : room1_ptr_(r1), room2_ptr_(r2) {}

  void Enter() override;

 private:
  RoomPtr room1_ptr_;
  RoomPtr room2_ptr_;
};

} // namespace dp

#endif // DOOR_H_
