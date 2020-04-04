#include "controller.h"
#include <iostream>
#include "SDL.h"

void Controller::HandleInput(bool &running, PongState &pong_state) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          pong_state.player_plate.direction = Plate::PlateDirection::kUp;
          break;
        case SDLK_DOWN:
          pong_state.player_plate.direction = Plate::PlateDirection::kDown;
          break;

      }
    } else {
      pong_state.player_plate.direction = Plate::PlateDirection::kNeutral;
    }
  }
}