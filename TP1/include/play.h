#ifndef PLAY_H
#define PLAY_H

#include <iostream>
#include <utility>
#include "vector.h"

class Play {
protected:
    std::string _playerName;
    int _bet;
    VectorCustom<std::string> _hand;
    std::string _classification;
    int _value;

public:
    Play();
    Play(std::string playerName, int bet, VectorCustom<std::string> hand);
    Play(std::string playerName, int bet, VectorCustom<std::string> hand, std::string classification, int value);

    std::string getPlayerName() const { return _playerName; }
    int getBet() const { return _bet; }
    VectorCustom<std::string> getHand() const { return _hand; }
    std::string getClassification() const { return _classification; }
    int getValue() const { return _value; }
    void setPlayerName(std::string playerName) { _playerName = std::move(playerName); }
    void setBet(int bet) { _bet = bet; }
    void setHand(VectorCustom<std::string> hand) { _hand = hand; }
    void setClassification(std::string classification) { _classification = std::move(classification); }
    void setValue(int value) { _value = value; }

    void generatePlayClassification();
    void generatePlayValue();
    void print();

    bool operator< (const Play &other) const {
        return _value < other.getValue();
    }
};

#endif //PLAY_H
