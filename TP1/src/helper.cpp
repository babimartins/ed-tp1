#include <iostream>
#include "../include/play.h"
#include "../include/helper.h"

Helper::Helper() = default;

VectorCustom<int> Helper::getCardNumbers(VectorCustom<std::string> hand) {
    VectorCustom<int> numbers;
    for (int i = 0; i < hand.length(); ++i) {
        std::string card = hand.get(i);
        std::string num = card.erase(card.length() - 1, 1);
        numbers.push(stoi(num));
    }
    numbers.sort();
    return numbers;
}

bool Helper::areCardsSameSuit(VectorCustom<std::string> hand) {
    if (!hand.empty()) {
        std::string firstCard = hand.get(0);
        char firstSuit = firstCard[firstCard.length() - 1];
        for (int i = 1; i < hand.length(); ++i) {
            std::string card = hand.get(i);
            char currSuit = card[card.length() - 1];
            if (firstSuit != currSuit) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Helper::areCardsInARow(VectorCustom<int> hand) {
    for (int i = 0; i < hand.length() - 1; ++i) {
        if (hand.get(i) + 1 != hand.get(i + 1)) {
            return false;
        }
    }
    return true;
}

bool Helper::isRoyalStraightFlush(VectorCustom<std::string> hand) {
    if (!Helper::areCardsSameSuit(hand)) {
        return false;
    }
    VectorCustom<int> numbers = Helper::getCardNumbers(hand);
    return (numbers.contains(10) &&
            numbers.contains(11) &&
            numbers.contains(12) &&
            numbers.contains(13) &&
            numbers.contains(1));
}

bool Helper::isStraightFlush(VectorCustom<std::string> hand) {
    if (!Helper::areCardsSameSuit(hand)) {
        return false;
    }
    VectorCustom<int> numbers = Helper::getCardNumbers(hand);
    return areCardsInARow(numbers);
}

bool Helper::isFourOfAKind(VectorCustom<std::string> hand) {
    VectorCustom<int> numbers = Helper::getCardNumbers(hand);
    if (numbers.get(0) != numbers.get(1)) {
        for (int i = 1; i < numbers.length() - 1; ++i) {
            if (numbers.get(i) != numbers.get(i + 1)) return false;
        }
    } else {
        for (int i = 0; i < numbers.length() - 2; ++i) {
            if (numbers.get(i) != numbers.get(i + 1)) return false;
        }
    }
    return true;
}

bool Helper::isFullHouse(VectorCustom<std::string> hand) {
    VectorCustom<int> numbers = Helper::getCardNumbers(hand);
    bool middleEl = (numbers.get(1) == numbers.get(2)) || (numbers.get(2) == numbers.get(3));
    return (numbers.get(0) == numbers.get(1)) && (numbers.get(3) == numbers.get(4)) && middleEl;
}

bool Helper::isFlush(VectorCustom<std::string> hand) {
    return Helper::areCardsSameSuit(hand);
}

bool Helper::isStraight(VectorCustom<std::string> hand) {
    VectorCustom<int> numbers = Helper::getCardNumbers(hand);
    return Helper::areCardsInARow(numbers);
}

bool Helper::isThreeOfAKind(VectorCustom<std::string> hand) {
    VectorCustom<int> numbers = Helper::getCardNumbers(hand);
    int middleNum = numbers.get(2);
    if ((middleNum == numbers.get(0) && middleNum == numbers.get(1)) ||
        (middleNum == numbers.get(1) && middleNum == numbers.get(3)) ||
        (middleNum == numbers.get(3) && middleNum == numbers.get(4))) {
        return true;
    }
    return false;
}

bool Helper::isTwoPairs(VectorCustom<std::string> hand) {
    VectorCustom<int> numbers = Helper::getCardNumbers(hand);
    if ((numbers.get(1) == numbers.get(2) && numbers.get(3) == numbers.get(4)) ||
        (numbers.get(0) == numbers.get(1) && numbers.get(2) == numbers.get(3)) ||
        (numbers.get(0) == numbers.get(1) && numbers.get(3) == numbers.get(4))) {
        return true;
    }
    return false;
}

bool Helper::isOnePair(VectorCustom<std::string> hand) {
    VectorCustom<int> numbers = Helper::getCardNumbers(hand);
    for (int i = 0; i < numbers.length(); ++i) {
        int firstNum = numbers.get(i);
        for (int j = i + 1; j < numbers.length(); ++j) {
            if (firstNum == numbers.get(j)) {
                return true;
            }
        }
    }
    return false;
}

VectorCustom<int> Helper::fourOfAKindTieBreak(VectorCustom<VectorCustom<std::string>> hands) {
    VectorCustom<int> fours;
    for (int i = 0; i < hands.length(); ++i) {
        VectorCustom<std::string> hand = hands.get(i);
        fours.push(stoi(hand.get(1)));
    }
    int biggerFours = fours.get(0);
    for (int i = 1; i < fours.length(); ++i) {
        if (fours.get(i) > biggerFours) biggerFours = fours.get(i);
    }
    VectorCustom<int> indexesFours;
    for (int i = 0; i < fours.length(); ++i) {
        if (fours.get(i) == biggerFours) {
            indexesFours.push(i);
        }
    }
    VectorCustom<int> extras;
    for (int i = 0; i < hands.length(); ++i) {
        VectorCustom<int> hand = getCardNumbers(hands.get(i));
        if (hand.get(0) != hand.get(1)) {
            extras.push(hand.get(0));
        } else {
            extras.push(hand.get(4));
        }
    }
    int biggerExtras = extras.get(0);
    for (int i = 1; i < extras.length(); ++i) {
        if (extras.get(i) > biggerExtras) biggerExtras = extras.get(i);
    }
    VectorCustom<int> indexesExtras;
    for (int i = 0; i < extras.length(); ++i) {
        if (extras.get(i) == biggerExtras) {
            indexesExtras.push(i);
        }
    }
    if (indexesExtras.empty()) indexesExtras.push(-1);
    return indexesExtras;
}

VectorCustom<Play> Helper::getWinnersTieBreak(VectorCustom<Play> tieWinners) {
    VectorCustom<VectorCustom<std::string>> hands;
    for (int i = 0; i < tieWinners.length(); ++i) {
        hands.push(tieWinners.get(i).getHand());
    }
    int playValue = tieWinners.get(0).getValue();
    switch (playValue) {
        case 10: case 9: {
            return tieWinners;
        }
        case 8: {
            VectorCustom<int> indexes = fourOfAKindTieBreak(hands);
            if (indexes.get(0) == -1) {
                return tieWinners;
            }
            VectorCustom<Play> winners;
            for (int i = 0; i < indexes.length(); ++i) {
                winners.push(tieWinners.get(indexes.get(i)));
            }
            return winners;
        }
        case 7: {
            break;
        }
        case 6: {
            break;
        }
        case 5: {
            break;
        }
        case 4: {
            break;
        }
        case 3: {
            break;
        }
        case 2: {
            break;
        }
        default: {
            return {};
        }
    }
}