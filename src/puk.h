#ifndef PUK_H
#define PUK_H

#include "plate.h"
#include "ai_plate.h"
#include "pong_component.h"
#include <chrono>
#include <random>

class PongState;
class AiPlate;

class Puk : public PongComponent {

public:
  Puk(int grid_width, int grid_height)
      : PongComponent(grid_width, grid_height), x_pos(grid_width / 2),
        y_pos(grid_height / 2), _random_engine((std::random_device())()),
        _random_y_proportion(0.1, 0.6), _last_update(_clock::now()) {}

  void update(Plate &player_plate, AiPlate &ai_plate, PongState &pong_state);
  float speed{1.4f};
  int positive_x_direction{1};
  float y_speed_proportion{0};
  float x_pos;
  float y_pos;
  float pause_duration;

private:
  typedef std::chrono::high_resolution_clock _clock;
  typedef std::chrono::duration<double, std::ratio<1, 1000>> _milliseconds;
  std::chrono::time_point<_clock> _last_update;
  std::mt19937 _random_engine;
  std::uniform_real_distribution<float> _random_y_proportion;
  void _reset_puk_to_mid();
};

#endif