#ifndef HELPER_H
#define HELPER_H

#include "play.h"

class Helper {
public:
    Helper();

    static VectorCustom<int> getCardNumbers(VectorCustom<std::string> hand);
    static bool areCardsSameSuit(VectorCustom<std::string> hand);
    static bool areCardsInARow(VectorCustom<int> hand);

    static bool isRoyalStraightFlush(VectorCustom<std::string> hand);
    static bool isStraightFlush(VectorCustom<std::string> hand);
    static bool isFourOfAKind(VectorCustom<std::string> hand);
    static bool isFullHouse(VectorCustom<std::string> hand);
    static bool isFlush(VectorCustom<std::string> hand);
    static bool isStraight(VectorCustom<std::string> hand);
    static bool isThreeOfAKind(VectorCustom<std::string> hand);
    static bool isTwoPairs(VectorCustom<std::string> hand);
    static bool isOnePair(VectorCustom<std::string> hand);

    static VectorCustom<int> getBiggerIndexes(VectorCustom<int> cards);
    static VectorCustom<int> fourOfAKindTieBreak(VectorCustom<VectorCustom<std::string>> hands);
    static VectorCustom<int> fullHouseOrThreeOfAKidTieBreak(VectorCustom<VectorCustom<std::string>> hands);
    static VectorCustom<int> flushOrStraightOrHighCardTieBreak(VectorCustom<VectorCustom<std::string>> hands);
    static VectorCustom<int> twoPairsOrOnePairTieBreak(VectorCustom<VectorCustom<std::string>> hands);
    static VectorCustom<Play> getWinnersTieBreak(VectorCustom<Play> tieWinners);
};

#endif //HELPER_H
