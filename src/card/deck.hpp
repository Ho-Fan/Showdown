#ifndef DECK_HPP
#define DECK_HPP
#include <vector>
#include "../card/card.hpp"



class Deck
{
private:
    std::vector<Card> cards;

public:
    Deck();
    void shuffle();
    Card deal_card();
};
#endif