#ifndef RESULT_H
#define RESULT_H
#include <utility>

#include "vector.h"
#include "player.h"

class Result {
protected:
    int _numWinners;
    int _amountWon;
    std::string _wonPlay;
    VectorCustom<std::string> _winners;

public:
    Result();
    Result(int numWinners, int amountWon, std::string wonPlay, VectorCustom<std::string> winners);

    int getNumWinners() const { return _numWinners; }
    int getAmountWon() const { return _amountWon; }
    std::string getWonPlay() const { return _wonPlay; }
    VectorCustom<std::string> getWinners() const { return _winners; }
    void setNumWinners(int numWinners) { _numWinners = numWinners; }
    void setAmountWon(int amountWon) { _amountWon = amountWon; }
    void setWonPlay(std::string wonPlay) { _wonPlay = std::move(wonPlay); }
    void setWinners(VectorCustom<std::string> winners) { _winners = winners; }

    void print();
};

#endif //RESULT_H
