#include <string>
#include <utility>
#include "../include/play.h"
#include "../include/helper.h"

Play::Play() {
    _playerName = "";
    _bet = 0;
    _hand = VectorCustom<std::string>();
    _classification = "";
    _value = 0;
}

Play::Play(std::string playerName, int bet, VectorCustom<std::string> hand) {
    _playerName = std::move(playerName);
    _bet = bet;
    _hand = hand;
    _classification = "";
    _value = 0;
}

Play::Play(std::string playerName, int bet, VectorCustom<std::string> hand, std::string classification, int value) {
    _playerName = std::move(playerName);
    _bet = bet;
    _hand = hand;
    _classification = std::move(classification);
    _value = value;
}

void Play::generatePlayClassification() {
    if (!_hand.empty()) {
        if (Helper::isRoyalStraightFlush(_hand)) {
            setClassification("RSF");
        } else if (Helper::isStraightFlush(_hand)) {
            setClassification("SF");
        } else if (Helper::isFourOfAKind(_hand)) {
            setClassification("FK");
        } else if (Helper::isFullHouse(_hand)) {
            setClassification("FH");
        } else if (Helper::isFlush(_hand)) {
            setClassification("F");
        } else if (Helper::isStraight(_hand)) {
            setClassification("S");
        } else if (Helper::isThreeOfAKind(_hand)) {
            setClassification("TK");
        } else if (Helper::isTwoPairs(_hand)) {
            setClassification("TP");
        } else if (Helper::isOnePair(_hand)) {
            setClassification("OP");
        } else {
            setClassification("HC");
        }
    }
}

void Play::generatePlayValue() {
    if (_classification == "RSF") {
        setValue(10);
    } else if (_classification == "SF") {
        setValue(9);
    } else if (_classification == "FK") {
        setValue(8);
    } else if (_classification == "FH") {
        setValue(7);
    } else if (_classification == "F") {
        setValue(6);
    } else if (_classification == "S") {
        setValue(5);
    } else if (_classification == "TK") {
        setValue(4);
    } else if (_classification == "TP") {
        setValue(3);
    } else if (_classification == "OP") {
        setValue(2);
    } else {
        setValue(1);
    }
}

void Play::print() {
    std::cout << _playerName << " " << _bet;
    for (int i = 0; i < _hand.length(); ++i) {
        std::cout << " " << _hand.get(i);
    }
    std::cout << " " << _classification;
    std::cout << " " << _value;
    std::cout << std::endl;
}
