#include "bombed_maze_creator.h"

using namespace dp;

int main(void) {
  MazeCreator ctor;
  std::shared_ptr<Maze> maze_ptr = ctor.GetMaze();

  BombedMazeCreator bmctor;
  std::shared_ptr<Maze> bmaze_ptr = bmctor.GetMaze();

  return 0;
}
