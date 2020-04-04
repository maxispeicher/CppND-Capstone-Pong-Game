#ifndef PLATE_H
#define PLATE_H

#include "pong_component.h"

class Plate : public PongComponent {
public:
  enum class PlateDirection { kUp, kDown, kNeutral };
  Plate(int grid_width, int grid_height, int plate_size)
      : PongComponent(grid_width, grid_height), y_pos(grid_height / 2),
        plate_size(plate_size) {}

  int plate_size;
  float y_pos;
  PlateDirection direction{PlateDirection::kNeutral};
  float speed{1.2f};
  void update();
};

#endif