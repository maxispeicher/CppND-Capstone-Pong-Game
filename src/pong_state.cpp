#include <iostream>
#include <string>
#include "pong_state.h"

void PongState::update() {
    player_plate.update();
    puk.update(player_plate, ai_plate, *this);
    ai_plate.update(puk);
}

std::string PongState::get_score() const {
    return "Player: " + std::to_string(player_points) + " - " + std::to_string(ai_points) + " :AI";
}