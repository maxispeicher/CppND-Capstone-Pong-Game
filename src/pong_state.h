#ifndef PONG_STATE_H
#define PONG_STATE_H

#include "SDL.h"
#include "plate.h"
#include "pong_component.h"
#include "puk.h"

class PongState : PongComponent {
private:
  float _puk_speed;

public:
  PongState(int grid_width, int grid_height, int plate_size)
      : PongComponent(grid_width, grid_height),
        puk(Puk(grid_width, grid_height)),
        player_plate(grid_width, grid_height, plate_size),
        ai_y_pos(grid_height / 2) {}

  void update();

  Puk puk;
  Plate player_plate;
  float ai_y_pos;
};

#endif