#ifndef AI_PLATE_H
#define AI_PLATE_H

#include "plate.h"
#include "puk.h"
#include <random>

class Puk;

class AiPlate : public Plate {
public:
  AiPlate(int grid_width, int grid_height, int plate_size)
      : Plate(grid_width, grid_height, plate_size),
        _random_engine((std::random_device())()),
        _random_offset(-2 * plate_size, 2 * plate_size) {}

  void update(Puk const &puk);

private:
  std::mt19937 _random_engine;
  std::uniform_real_distribution<float> _random_offset;
  float _predict_puk_impact(Puk const &puk);
};

#endif