#include "ai_plate.h"
#include "puk.h"

void AiPlate::update(Puk const &puk) {
  float predicted_impact = _predict_puk_impact(puk);
  float target_y = predicted_impact + _random_offset(_random_engine);

  float delta_y = target_y - y_pos;

  if (abs(delta_y) > 0.5) {
      if (delta_y > 0) {
          y_pos += speed;
      } else {
          y_pos -= speed;
      }
  }

  float lower_limit = (float)(plate_size / 2);
  float upper_limit = _grid_height - (float)(plate_size / 2) - 1;

  if (y_pos < lower_limit) {
    y_pos = lower_limit;
  } else if (y_pos >= upper_limit) {
    y_pos = upper_limit;
  }
}

float AiPlate::_predict_puk_impact(Puk const &puk) {
  if (puk.positive_x_direction != 1 || puk.pause_duration > 0) {
    return _grid_height / 2;
  } else {
    float delta_x = _grid_width - puk.x_pos;
    float y_impact = puk.y_pos + delta_x * puk.y_speed_proportion;
    float y_impact_mod = fmod(y_impact, _grid_height);
    if (y_impact < 0) {
      y_impact = abs(y_impact_mod);
    } else if (y_impact > _grid_height) {
      y_impact = 2 * _grid_height - y_impact_mod;
    }
    return y_impact;
  }
}