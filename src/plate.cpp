#include "plate.h"

void Plate::update() {
    switch (direction)
    {
    case PlateDirection::kUp:
        y_pos -= speed;
        break;
    case PlateDirection::kDown:
        y_pos += speed;
        break;
    default:
        break;
    }

    float lower_limit = (float)(plate_size/2);
    float upper_limit = _grid_height - (float)(plate_size/2) - 1;

    if (y_pos < lower_limit) {
        y_pos = lower_limit;
    } else if (y_pos >= upper_limit) {
        y_pos = upper_limit;
    }
}