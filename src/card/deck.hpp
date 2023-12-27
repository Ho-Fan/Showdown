#ifndef DECK_HPP
#define DECK_HPP
#include <vector>
#include <memory>
#include <algorithm>
#include <random>
#include "../card/card.hpp"



class Deck
{
private:
    std::vector<std::unique_ptr<Card>> cards;

public:
    Deck();
    void shuffle_cards();
    std::unique_ptr<Card> deal_card();
};
#endif