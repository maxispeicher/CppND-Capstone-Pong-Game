#include <iostream>
#include <stdlib.h>
#include "pong_state.h"

void PongState::update() {
    player_plate.update();
    puk.update();
}