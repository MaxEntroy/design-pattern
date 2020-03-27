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
