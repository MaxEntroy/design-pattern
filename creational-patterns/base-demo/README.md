## base-demo

本小节讲了这一张开篇的一个基础例子。之后展开的各个章节都是在这个基础上进行扩展的。
我不得不承认的一点是，设计模式这本书本身讲解的一些例子，确实需要反复体会，并不是简简单单就能理解的。
之所以要先说下这个例子，因为是从某种解读来说，虽然作者对于base-demo的例子手法不认可，但是我觉得他也有可取的地方，所以我们先来说下。

### 问题

需要设计迷宫，迷宫有一下部分组成，
- room
- door
- wall
- 他们的基本操作都是enter

其内在逻辑是这样，
- maze由若干room组成
- room由door和wall组成
- 每个door关联两个room

那么需要我们设计出这样一个迷宫来。

### 解决

- 思路
  - 整体的逻辑“自顶向下”，自上而下的顺序是: maze->room->door and wall
  - 发现基础组件的共性，用oo组织他们.

具体来说

一个迷宫由若干rooms组成。本例全部采用dynamic object进行组织，这么考虑的原因是程序一开始，可能并不清楚需要多少room

```cpp
// maze.h
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
```

用oo来组织room,door,wall之间的共享，并在具体类设计当中体现内在逻辑关系(room由door和wall组成)
```cpp
// map_site.h
#ifndef MAP_SITE_H_
#define MAP_SITE_H_

namespace dp {

class MapSite {
 public:
  virtual ~MapSite() {}

  virtual void Enter() = 0;

};

} // namespace dp

#endif // MAP_SITE_H_

// room.h
#ifndef ROOM_H_
#define ROOM_H_

#include <memory>
#include <vector>

#include "map_site.h"

namespace dp {

enum Direction {
  kNorth,
  kSouth,
  kEast,
  kWest
};

class Room : public MapSite {
 public:
  typedef std::shared_ptr<MapSite> MSPtr;

 public:
  Room() : room_no_(-1) {}
  explicit Room(int rn) : room_no_(rn) {
    sides_.resize(4);
  }

 public:
  int GetRoomNo() const { return room_no_; }
  void SetRoomNo(int rn) { room_no_ = rn; }

  MSPtr GetSide(Direction dir) const { return sides_[dir]; }
  void SetSide(Direction dir, MSPtr p) { sides_[dir] = p; }

  void Enter() override;

 private:
  int room_no_;
  std::vector<MSPtr> sides_;
};

} // namespace dp

#endif // ROOM_H_

// door.h
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

// wall.h
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
```

q:紧接而来面临的问题是，程序如何组织?
>我们发现maze的构造，不能直接通过提供一个constructor就完成。因为它包含了其他的对象，
其它对象的构造相对复杂，所以maze的构造需要再提供一段逻辑才能完成。
>
>此时，作者给出了一种非常好的设计，由提供了一个类(MazeGame)，我个人觉得这也算某种意义上的factory，
来封装较为复杂的maze构造，使得client只关心如何拿到Maze，而不关心Maze的构造。

```cpp
// maze_game.h
#ifndef MAZE_GAME_H_
#define MAZE_GAME_H_

#include "maze.h"

namespace dp {

class MazeGame {
 public:
  MazeGame() {}

  std::shared_ptr<Maze> CreateMaze() const;
};

} // namespace dp

#endif // MAZE_GAME_H_

// main.cc
#include "maze_game.h"

using namespace dp;

int main(void) {
  MazeGame game;

  std::shared_ptr<Maze> maze_ptr = game.CreateMaze();

  return 0;
}
```

q:既然我也认可作者的做法，那作者又觉得这种设计的问题在哪里呢？
>作者是认为这种方式时属于硬编码的方式，对于Maze的构造逻辑写死了，没有灵活性。
>
>可是maze也只能这么构造，并没有别的办法。作者认为，这种方式(提供CreateMaze())真的的问题，不在于他的大小。
而在于，这么实现不够灵活，这完全是一种设计上的考虑，所以，对于我的质疑，作者并没有否定，即这个构造的逻辑没问题，只是不够灵活。
当我们希望改变布局时，显然这个函数需要重新实现，显然这种做法是没有考虑到重用性。
>
>这个结论我是认可的，对于构造的逻辑，没有办法，只能这么做。但是这么设计确实没有考虑到重用性。

那么我们详细来说下，对于下面这段硬编码的代码，我们考虑如下问题：
1. 如果此时需求改变，Room做了一些改变，有一个新的SpellRoom，它由Wall，door，mirror(这是一面镜子，对他念咒语，可能会开或者不开)构成.那么下面代码中，所有Room需要改变
2. 因为Room变成DoorRoom，所以构造时，也需要加入Mirror，此时Room的构造逻辑发生变化。代码也需要增加这一部分。

所以，我们轻易能发现，下面这段代码，确实存在无法重用的地步。
所以，对于Maze而言，我认为作者提供了类似于工厂的方法来获得，但是对于其它的组件，并没有类似工厂方法来帮助执行逻辑和底层组件进行解耦，这就是构造代码中暴露出来的问题。

```cpp
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
```