#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "pong_state.h"

void Controller::HandleInput(bool &running, PongState &pong_state) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          pong_state.player_direction = PongState::PlateDirection::kUp;
          break;
        case SDLK_DOWN:
          pong_state.player_direction = PongState::PlateDirection::kDown;
          break;

      }
    } else {
      pong_state.player_direction = PongState::PlateDirection::kNeutral;
    }
  }
}