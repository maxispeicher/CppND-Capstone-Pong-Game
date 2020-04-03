#include <iostream>
#include <stdlib.h>
#include "pong_state.h"

void PongState::update() {
    switch (player_direction)
    {
    case PlateDirection::kUp:
        player_y_pos -= plate_speed;
        break;
    case PlateDirection::kDown:
        player_y_pos += plate_speed;
        break;
    default:
        break;
    }

    float lower_limit = (float)(plate_size/2);
    float upper_limit = _grid_height - (float)(plate_size/2) - 1;

    if (player_y_pos < lower_limit) {
        player_y_pos = lower_limit;
    } else if (player_y_pos >= upper_limit) {
        player_y_pos = upper_limit;
    }

    puk_x_pos += puk_speed * (1 - abs(puk_y_speed_proportion)) * positive_x_puk_direction;
    if (puk_x_pos >= _grid_width || puk_x_pos <= 0) {
        positive_x_puk_direction *= -1;
    }

    puk_y_pos += puk_y_speed_proportion * puk_speed;
    if (puk_y_pos >= _grid_height || puk_y_pos <= 0) {
        puk_y_speed_proportion *= -1;
    }
    std::cout << "Puk x pos: " << puk_x_pos << "; Puk y pos: " << puk_y_pos << std::endl; 
}