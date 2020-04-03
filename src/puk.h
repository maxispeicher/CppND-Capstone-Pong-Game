#ifndef PUK_H
#define PUK_H

#include "SDL.h"

class Puk {
public:
  Puk(int grid_width, int grid_height)
      : _grid_width(grid_width), _grid_height(grid_height),
        x_pos(grid_width / 2), y_pos(grid_height / 2) {}

  void Update();
  float x_pos;
  float y_pos;

private:
  int _grid_width;
  int _grid_height;
};

#endif