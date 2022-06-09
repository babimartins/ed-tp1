#include <utility>
#include "../include/player.h"

Player::Player() {
    _name = "";
    _totalAmount = 0;
}

Player::Player(std::string name, int totalAmount) {
    _name = std::move(name);
    _totalAmount = totalAmount;
}

void Player::print() {
    std::cout << _name << " " << _totalAmount << std::endl;
}
