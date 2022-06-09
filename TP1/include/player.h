#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "vector.h"

class Player {
protected:
    std::string _name;
    int _totalAmount;

public:
    Player();
    Player(std::string name, int totalAmount);

    std::string getPlayerName() const { return _name; }
    int getTotalAmount() const { return _totalAmount; }
    void setPlayerName(std::string name) { _name = std::move(name); }
    void setTotalAmount(int totalAmount) { _totalAmount = totalAmount; }

    void print();
};

#endif //PLAYER_H
