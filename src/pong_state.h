#ifndef PONG_STATE_H
#define PONG_STATE_H

#include "SDL.h"

class PongState {
private:
  float _puk_speed;
  int _grid_width;
  int _grid_height;

public:
  enum class PlateDirection { kUp, kDown, kNeutral };

  PongState(int grid_width, int grid_height, int plate_size)
      : _grid_width(grid_width), _grid_height(grid_height),
        puk_x_pos(grid_width / 2), puk_y_pos(grid_height / 2),
        plate_size(plate_size), player_y_pos(grid_height / 2),
        ai_y_pos(grid_height / 2) {}

  void update();

  float puk_x_pos;
  float puk_y_pos;
  float player_y_pos;
  float ai_y_pos;
  int plate_size;
  PlateDirection player_direction;
  float plate_speed{0.4f};
  float puk_speed{0.6f};
  int positive_x_puk_direction{1};
  float puk_y_speed_proportion{0};
};

#endif