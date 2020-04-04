#include "puk.h"
#include "ai_plate.h"
#include "pong_state.h"
#include <chrono>
#include <iostream>

void Puk::update(Plate &player_plate, AiPlate &ai_plate,
                 PongState &pong_state) {
  if (pause_duration > 0) {
    pause_duration -=
        std::chrono::duration_cast<_milliseconds>(_clock::now() - _last_update)
            .count();
  } else {
    pause_duration = 0;
    x_pos += speed * (1 - abs(y_speed_proportion)) * positive_x_direction;
    if (x_pos <= 1) {
      if (x_pos >= -1) {
        if (y_pos >= player_plate.y_pos - (player_plate.plate_size / 2) - 1 &&
            y_pos <= player_plate.y_pos + (player_plate.plate_size / 2)) {
          positive_x_direction *= -1;
          x_pos += speed * (1 - abs(y_speed_proportion)) * positive_x_direction;
          y_speed_proportion = _random_y_proportion(_random_engine);
        }
      } else {
        std::cout << "Goal for AI" << std::endl;
        pong_state.ai_points += 1;
        _reset_puk_to_mid();
        pause_duration = 3000;
      }
    } else if (x_pos >= _grid_width - 1) {
      if (x_pos <= _grid_width + 1) {
        if (y_pos >= ai_plate.y_pos - (ai_plate.plate_size / 2) - 1 &&
            y_pos <= ai_plate.y_pos + (ai_plate.plate_size / 2)) {
          positive_x_direction *= -1;
          x_pos += speed * (1 - abs(y_speed_proportion)) * positive_x_direction;
          y_speed_proportion = _random_y_proportion(_random_engine);
        }
      } else {
        std::cout << "Goal for Player" << std::endl;
        pong_state.player_points += 1;
        _reset_puk_to_mid();
        pause_duration = 3000;
      }
    }

    y_pos += y_speed_proportion * speed;
    if (y_pos >= _grid_height || y_pos <= 0) {
      y_speed_proportion *= -1;
    }
  }
  _last_update = _clock::now();
}

void Puk::_reset_puk_to_mid() {
  x_pos = _grid_width / 2;
  y_pos = _grid_height / 2;
}