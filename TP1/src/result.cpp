#include <utility>
#include "../include/result.h"

Result::Result() {
    _numWinners = 0;
    _amountWon = 0;
    _wonPlay = "";
    _winners = VectorCustom<std::string>();
}

Result::Result(int numWinners, int amountWon, std::string wonPlay, VectorCustom<std::string> winners) {
    _numWinners = numWinners;
    _amountWon = amountWon;
    _wonPlay = std::move(wonPlay);
    _winners = winners;
}

void Result::print() {
    std::cout << _numWinners << " " << _amountWon << " " << _wonPlay << std::endl;
    _winners.sort();
    for (int i = 0; i < _winners.length(); i++) {
        std::cout << _winners.get(i) << std::endl;
    }
}
