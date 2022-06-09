#ifndef MATCH_H
#define MATCH_H

#include <iostream>
#include "vector.h"
#include "round.h"
#include "player.h"

class Match {
protected:
    int _numRounds;
    int _initAmount;
    VectorCustom<Round> _rounds;
    VectorCustom<Player> _players;

public:
    Match();
    Match(int numRounds, int initAmount, VectorCustom<Round> rounds, VectorCustom<Player> players);

    int getNumRounds() const { return _numRounds; }
    int getInitAmount() const { return _initAmount; }
    VectorCustom<Round> getRounds() const { return _rounds; }
    VectorCustom<Player> getPlayers() const { return _players; }
    void setNumRounds(int numRounds) { _numRounds = numRounds; }
    void setInitAmount(int initAmount) { _initAmount = initAmount; }
    void setRounds(VectorCustom<Round> rounds) { _rounds = rounds; }
    void setPlayers(VectorCustom<Player> players) { _players = players; }

    void updatePlayer(const Player& player);
    void generateMatchResults();
    void printResults();
    void print();
};

#endif //MATCH_H
