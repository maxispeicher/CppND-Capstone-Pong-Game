#ifndef PUK_H
#define PUK_H

#include "pong_component.h"

class Puk : PongComponent {

public:
  Puk(int grid_width, int grid_height)
      : PongComponent(grid_width, grid_height), x_pos(grid_width / 2),
        y_pos(grid_height / 2) {}

  void update();
  float speed{0.6f};
  int positive_x_direction{1};
  float y_speed_proportion{0};
  float x_pos;
  float y_pos;
};

#endif