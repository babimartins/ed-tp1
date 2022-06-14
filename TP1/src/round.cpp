#include <utility>
#include "../include/round.h"
#include "../include/helper.h"

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
    bool isInvalidRound = false;
    for (int i = 0; i < players.length(); ++i) {
        Player player = players.get(i);
        int totalAmount = player.getTotalAmount();;
        Play play;
        for (int j = 0; j < _plays.length(); ++j) {
            if (_plays.get(j).getPlayerName() == player.getPlayerName()) {
                play = _plays.get(j);
                break;
            }
        }
        int bet = _initBet + play.getBet();
        if (totalAmount < bet) {
            isInvalidRound = true;
        }
    }
    if (isInvalidRound) {
        Result result = Result(0, 0, "I", VectorCustom<std::string>());
        setResult(result);
    } else {
        for (int i = 0; i < players.length(); ++i) {
            Player player = players.get(i);
            Play play;
            for (int j = 0; j < _plays.length(); ++j) {
                if (_plays.get(j).getPlayerName() == player.getPlayerName()) {
                    play = _plays.get(j);
                    break;
                }
            }
            int winnerAmount = player.getTotalAmount();
            int bet = _initBet + play.getBet();
            player.setTotalAmount(winnerAmount - bet);
            players.push(player, i);
        }
        VectorCustom<Play> updatedPlays;
        for (int i = 0; i < _plays.length(); ++i) {
            Play play = _plays.get(i);
            play.generatePlayClassification();
            play.generatePlayValue();
            updatedPlays.push(play);
        }
        updatedPlays.sort();
        setPlays(updatedPlays);
        Play lastWinner = _plays.get(_plays.length() - 1);
        VectorCustom<Play> tieWinners;
        for (int i = 0; i < _plays.length(); ++i) {
            Play play = _plays.get(i);
            if (play.getValue() == lastWinner.getValue()) {
                tieWinners.push(play);
            }
        }
        VectorCustom<Play> winners = Helper::getWinnersTieBreak(tieWinners);
        VectorCustom<std::string> winnersNames;
        for (int i = 0; i < winners.length(); ++i) {
            Play play = winners.get(i);
            winnersNames.push(play.getPlayerName());
        }
        int totalAmount = (_initBet * players.length());
        for (int i = 0; i < _plays.length(); ++i) {
            totalAmount += _plays.get(i).getBet();
        }
        totalAmount /= winners.length();
        for (int i = 0; i < players.length(); ++i) {
            if (winnersNames.contains(players.get(i).getPlayerName())) {
                Player winner = players.get(i);
                int winnerAmount = winner.getTotalAmount();
                winner.setTotalAmount(winnerAmount + totalAmount);
                players.push(winner, i);
            }
        }
        Result result = Result(winners.length(), totalAmount, lastWinner.getClassification(), winnersNames);
        setResult(result);
    }
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