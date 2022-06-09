#ifndef HELPER_H
#define HELPER_H

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
};

#endif //HELPER_H
