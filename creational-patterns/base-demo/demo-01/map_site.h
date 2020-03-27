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
