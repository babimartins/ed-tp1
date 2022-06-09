#ifndef ROUND_H
#define ROUND_H

#include <iostream>
#include <utility>
#include "vector.h"
#include "play.h"
#include "result.h"

class Round {
protected:
    int _numPlays;
    int _initBet;
    VectorCustom<Play> _plays;
    Result _result;

public:
    Round();
    Round(int numPlays, int initBet, VectorCustom<Play> plays, Result _result);

    int getNumPlays() const { return _numPlays; }
    int getInitBet() const { return _initBet; }
    Result getResult() const { return _result; }
    VectorCustom<Play> getPlays() const { return _plays; }
    void setNumPlays(int numPlays) { _numPlays = numPlays; }
    void setInitBet(int initBet) { _initBet = initBet; }
    void setResult(Result result) { _result = std::move(result); }
    void setPlays(VectorCustom<Play> plays) { _plays = plays; }

    void generateResult(VectorCustom<Player> players);
    void printResult();
    void print();
};

#endif //ROUND_H
