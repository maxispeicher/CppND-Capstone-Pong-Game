#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "pong_state.h"

class Controller {
 public:
  void HandleInput(bool &running, PongState &pong_state) const;
};

#endif