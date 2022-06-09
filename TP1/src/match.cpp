#include "../include/match.h"

Match::Match() {
    _numRounds = 0;
    _initAmount = 0;
    _rounds = VectorCustom<Round>();
    _players = VectorCustom<Player>();
}

Match::Match(int numRounds, int initAmount, VectorCustom<Round> rounds, VectorCustom<Player> players) {
    _numRounds = numRounds;
    _initAmount = initAmount;
    _rounds = rounds;
    _players = players;
}

void Match::updatePlayer(const Player& player) {
    bool hasPlayer = false;
    for (int i = 0; i < _players.length(); ++i) {
        Player p = _players.get(i);
        if (p.getPlayerName() == player.getPlayerName()) {
            hasPlayer = true;
            p.setTotalAmount(player.getTotalAmount());
            _players.push(p, i);
        }
    }
    if (!hasPlayer) {
        _players.push(player);
    }
}

void Match::generateMatchResults() {
    VectorCustom<Round> newRounds;
    for (int i = 0; i < _numRounds; ++i) {
        Round round = _rounds.get(i);
        round.generateResult(_players);
        newRounds.push(round);
    }
    setRounds(newRounds);
}

void Match::printResults() {
    for (int i = 0; i < _numRounds; ++i) {
        Round round = _rounds.get(i);
        round.printResult();
    }
}

void Match::print() {
    std::cout << _numRounds << " " << _initAmount << std::endl;
    for (int i = 0; i < _numRounds; ++i) {
        _rounds.get(i).print();
    }
}
