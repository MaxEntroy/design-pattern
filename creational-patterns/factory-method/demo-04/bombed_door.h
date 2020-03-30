#ifndef BOMBED_DOOR_H_
#define BOMBED_DOOR_H_

#include "door.h"

namespace dp {

class BombedDoor : public Door {
 public:
  BombedDoor() : Door() {}
  BombedDoor(RoomPtr rm1_ptr, RoomPtr rm2_ptr) : Door(rm1_ptr, rm2_ptr) {}

  void Enter() override;
};

} // namespace dp

#endif // BOMBED_DOOR_H_
