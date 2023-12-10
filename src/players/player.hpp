#include <vector>
#include <string>
#include "card/deck.hpp"
#include "card/card.hpp"
#include "players/exchangeHands.hpp"
#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    protected:
        std::string name;
        int points;
        std::vector<Card> hands;

    public:
        Play();
        void name_himself(const std::string& name);
        void exchange_hands(player& other);
        virtual Card show_card() = 0;
        void draw_card(Deck& deck);
};

#endif