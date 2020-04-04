#include <iostream>
#include "puk.h"

void Puk::update() {
    x_pos += speed * (1 - abs(y_speed_proportion)) * positive_x_direction;
    if (x_pos >= _grid_width || x_pos <= 0) {
        positive_x_direction *= -1;
    }

    y_pos += y_speed_proportion * speed;
    if (y_pos >= _grid_height || y_pos <= 0) {
        y_speed_proportion *= -1;
    }
    std::cout << "Puk x pos: " << x_pos << "; Puk y pos: " << y_pos << std::endl; 
}