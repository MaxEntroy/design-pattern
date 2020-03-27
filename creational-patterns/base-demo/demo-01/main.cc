#include "maze_game.h"

using namespace dp;

int main(void) {
  MazeGame game;

  std::shared_ptr<Maze> maze_ptr = game.CreateMaze();

  return 0;
}
