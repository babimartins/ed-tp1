#include <utility>
#include "../include/round.h"

Round::Round() {
    _numPlays = 0;
    _initBet = 0;
    _plays = VectorCustom<Play>();
    _result = Result();
}

Round::Round(int numPlays, int initBet, VectorCustom<Play> plays, Result result) {
    _numPlays = numPlays;
    _initBet = initBet;
    _plays = plays;
    _result = std::move(result);
}

void Round::generateResult(VectorCustom<Player> players) {
    VectorCustom<Play> updatedPlays;
    for (int i = 0; i < _plays.length(); ++i) {
        Play play = _plays.get(i);
        play.generatePlayClassification();
        play.generatePlayValue();
        updatedPlays.push(play);
    }
    updatedPlays.sort();
    setPlays(updatedPlays);
    Play winner = _plays.get(_plays.length() - 1);
    VectorCustom<Play> tieWinners;
    for (int i = 0; i < _plays.length(); ++i) {
        Play play = _plays.get(i);
        if (play.getValue() == winner.getValue()) {
            tieWinners.push(play);
        }
    }
    VectorCustom<std::string> winnersNames;
    for (int i = 0; i < tieWinners.length(); ++i) {
        Play play = tieWinners.get(i);
        winnersNames.push(play.getPlayerName());
    }
    int totalAmount = (_initBet * players.length());
    for (int i = 0; i < _plays.length(); ++i) {
        totalAmount += _plays.get(i).getBet();
    }
    Result result = Result(tieWinners.length(), totalAmount / tieWinners.length(), winner.getClassification(), winnersNames);
    setResult(result);
}

void Round::print() {
    std::cout << _numPlays << " " << _initBet << std::endl;
    for (int i = 0; i < _plays.length(); ++i) {
        _plays.get(i).print();
    }
}

void Round::printResult() {
    _result.print();
}