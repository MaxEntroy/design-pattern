## factory-method实现

q:对于base-demo，自己的尝试会是怎样?
>本质来说，我觉得base-demo实现了一个具体的maze和maze_creator，没有高层次的抽象，可能这是一种简单工厂模式。
maze_creator的作用在于封住对于maze的构造，因为maze的构造略显麻烦。采用简单工厂模式之后，业务代码不用关心这个复杂对象的构造。
所以，我认为base-demo的实现没有问题了。

q:作者又是如何思考的？
>作者的思路就是，没有拘泥于工厂模式的表象。
作者在书中其实也提到了工厂模式的其余作用，为子类提供hook以及连接平行类的层次。
作者在这里的思考更多的是为子类提供hook，使得代码的复用性提高
>
>具体来说，作者将所有组件，提供工厂方法。使得对于组件的派生，不影响对于Maze的构造。

```cpp
// map_site.h
// room.h
// wall.h
// door.h
// maze.h

// maze_creator.h
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

// maze_creator.cc
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
```

作者还是采用了NVI的手法，提供了对于基础组件的工厂函数。好处在于，如果基础组件有变化，那么只需修改对于基础组件的工厂方法即可。而不用修改GetMaze函数。代码复用性增强。，灵活性增强

```cpp
// bombed_door.h
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

// bombed_maze_creator.h
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

// bombed_maze_creator.cc
#include "bombed_door.h"
#include "bombed_maze_creator.h"

namespace dp {

MazeCreator::DoorPtr BombedMazeCreator::MakeDoor(MazeCreator::RoomPtr rm1_ptr, MazeCreator::RoomPtr rm2_ptr) {
  return std::make_shared<BombedDoor>(rm1_ptr, rm2_ptr);
}

} // namespace dp
```