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

VectorCustom<int> Helper::getBiggerIndexes(VectorCustom<int> cards) {
    for (int i = 0; i < cards.length(); ++i) {
        if (cards.get(i) == 1) {
            cards.push(14, i);
        }
    }
    int bigger = cards.get(0);
    for (int i = 1; i < cards.length(); ++i) {
        if (cards.get(i) > bigger) bigger = cards.get(i);
    }
    VectorCustom<int> indexes;
    for (int i = 0; i < cards.length(); ++i) {
        if (cards.get(i) == bigger) {
            indexes.push(i);
        }
    }
    return indexes;
}

VectorCustom<int> Helper::fourOfAKindTieBreak(VectorCustom<VectorCustom<std::string>> hands) {
    VectorCustom<int> fours;
    for (int i = 0; i < hands.length(); ++i) {
        VectorCustom<int> hand = getCardNumbers(hands.get(i));
        fours.push(hand.get(1));
    }
    VectorCustom<int> indexesFours = getBiggerIndexes(fours);
    if (indexesFours.length() == 1) {
        return indexesFours;
    } else {
        VectorCustom<int> extras;
        for (int i = 0; i < hands.length(); ++i) {
            VectorCustom<int> hand = getCardNumbers(hands.get(i));
            if (hand.get(0) != hand.get(1)) {
                extras.push(hand.get(0));
            } else {
                extras.push(hand.get(4));
            }
        }
        VectorCustom<int> indexesExtras = getBiggerIndexes(extras);
        return indexesExtras;
    }
}

VectorCustom<int> Helper::fullHouseOrThreeOfAKidTieBreak(VectorCustom<VectorCustom<std::string>> hands) {
    VectorCustom<int> threes;
    for (int i = 0; i < hands.length(); ++i) {
        VectorCustom<int> hand = getCardNumbers(hands.get(i));
        threes.push(hand.get(1));
    }
    VectorCustom<int> indexesThrees = getBiggerIndexes(threes);
    if (indexesThrees.length() == 1) {
        return indexesThrees;
    } else {
        VectorCustom<int> extras;
        for (int i = 0; i < hands.length(); ++i) {
            VectorCustom<int> hand = getCardNumbers(hands.get(i));
            int bigger;
            if (hand.get(0) != hand.get(1)) {
                bigger = hand.get(0) > hand.get(1) ? hand.get(0) : hand.get(1);
            } else {
                bigger = hand.get(3) > hand.get(4) ? hand.get(3) : hand.get(4);
            }
            extras.push(bigger);
        }
        VectorCustom<int> indexesExtras = getBiggerIndexes(extras);
        return indexesExtras;
    }
}

VectorCustom<int> Helper::flushOrStraightOrHighCardTieBreak(VectorCustom<VectorCustom<std::string>> hands) {
    VectorCustom<int> biggers;
    for (int i = 0; i < hands.length(); ++i) {
        VectorCustom<int> hand = getCardNumbers(hands.get(i));
        hand.sort();
        if (hand.get(0) == 1) {
            biggers.push(hand.get(0));
        } else {
            biggers.push(hand.get(4));
        }
    }
    VectorCustom<int> indexes = getBiggerIndexes(biggers);
    return indexes;
}

VectorCustom<int> Helper::twoPairsOrOnePairTieBreak(VectorCustom<VectorCustom<std::string>> hands) {
    VectorCustom<VectorCustom<int>> handsNumbers;
    for (int i = 0; i < hands.length(); ++i) {
        VectorCustom<int> hand = getCardNumbers(hands.get(i));
        hand.sort();
        handsNumbers.push(hand);
    }
    VectorCustom<int> twos;
    for (int i = 0; i < handsNumbers.length(); ++i) {
        twos.push(handsNumbers.get(i).get(3));
    }
    VectorCustom<int> indexes = getBiggerIndexes(twos);
    if (indexes.length() == 1) {
        return indexes;
    } else {
        VectorCustom<int> extras;
        for (int i = 0; i < indexes.length(); ++i) {
            VectorCustom<int> hand = handsNumbers.get(indexes.get(i));
            if (hand.get(0) == hand.get(1) || hand.get(1) == hand.get(2)) {
                extras.push(hand.get(1));
            } else if (hand.get(3) == hand.get(4)) {
                extras.push(hand.get(2));
            } else {
                extras.push(hand.get(4));
            }
        }
        indexes = getBiggerIndexes(extras);
        if (indexes.length() == 1) {
            return indexes;
        }
    }
    VectorCustom<int> extras;
    for (int i = 0; i < indexes.length(); ++i) {
        VectorCustom<int> hand = handsNumbers.get(indexes.get(i));
        for (int j = 0; j < hand.length(); ++j) {
            if (hand.get(j) == 1) {
                hand.push(14, j);
            }
        }
        hand.sort();
        int different = hand.get(0);
        if (hand.get(0) == hand.get(1)) {
            if (hand.get(3) == hand.get(4)) {
                different = hand.get(2);
            } else {
                different = hand.get(4);
            }
        } else if (hand.get(1) == hand.get(2) && hand.get(3) != hand.get(4)) {
            different = hand.get(4);
        }
        extras.push(different);
    }
    indexes = getBiggerIndexes(extras);
    return indexes;
}

VectorCustom<Play> Helper::getWinnersTieBreak(VectorCustom<Play> tieWinners) {
    VectorCustom<VectorCustom<std::string>> hands;
    for (int i = 0; i < tieWinners.length(); ++i) {
        hands.push(tieWinners.get(i).getHand());
    }
    VectorCustom<int> indexes;
    int playValue = tieWinners.get(0).getValue();
    switch (playValue) {
        case 10: case 9:
            return tieWinners;
        case 8:
            indexes = fourOfAKindTieBreak(hands);
            break;
        case 7: case 4:
            indexes = fullHouseOrThreeOfAKidTieBreak(hands);
            break;
        case 6: case 5: case 1:
            indexes = flushOrStraightOrHighCardTieBreak(hands);
            break;
        case 3: case 2:
            indexes = twoPairsOrOnePairTieBreak(hands);
            break;
        default:
            return tieWinners;
    }
    if (indexes.empty()) {
        return tieWinners;
    }
    VectorCustom<Play> winners;
    for (int i = 0; i < indexes.length(); ++i) {
        winners.push(tieWinners.get(indexes.get(i)));
    }
    return winners;
}