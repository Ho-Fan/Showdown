#ifndef DECK_HPP
#define DECK_HPP
#include <vector>
#include <memory>
#include "../card/card.hpp"



class Deck
{
private:
    std::vector<std::unique_ptr<Card>> cards;

public:
    Deck();
    void shuffle();
    std::unique_ptr<Card> deal_card();
};
#endif