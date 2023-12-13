#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <vector>
#include <string>
#include "../card/deck.hpp"
#include "../card/card.hpp"



class Player
{
    protected:
        std::string name;
        int points;
        std::vector<Card> hands;

    public:
        Player();
        void name_himself(const std::string& name);
        void exchange_hands(Player& other);
        virtual Card show_card() = 0;
        void draw_card(Deck& deck);
};

#endif