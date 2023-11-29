#include <vector>
#include <string>
#include "card/deck.h"
#include "card/card.h"
#include "players/exchangeHands.h"
#ifndef PLAYER_H
#define PLAYER_H


class Player
{
protected:
    std::vector<Card> hands;
    std::string name;
    int points;

public:
    void name_himself(const std::string& name);
    void exchange_hands(player& other);
    virtual Card show_card() = 0;
    void draw_card(Deck& deck);
};

#endif