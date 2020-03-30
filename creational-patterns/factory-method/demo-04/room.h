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

