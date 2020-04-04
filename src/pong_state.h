#ifndef PONG_STATE_H
#define PONG_STATE_H

#include <string>
#include "SDL.h"
#include "plate.h"
#include "pong_component.h"
#include "puk.h"
#include "ai_plate.h"

class PongState : public PongComponent {
private:
  float _puk_speed;

public:
  PongState(int grid_width, int grid_height, int plate_size)
      : PongComponent(grid_width, grid_height),
        puk(Puk(grid_width, grid_height)),
        player_plate(grid_width, grid_height, plate_size),
        ai_plate(grid_width, grid_height, plate_size) {}

  void update();
  std::string get_score() const;

  Puk puk;
  Plate player_plate;
  AiPlate ai_plate;
  float ai_y_pos;
  int player_points;
  int ai_points;
};

#endif