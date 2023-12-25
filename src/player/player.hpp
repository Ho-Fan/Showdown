#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "../card/deck.hpp"
#include "../card/card.hpp"


class Player
{
protected:
    std::string playerOrdinal;
    std::string name;
    int points = 0;
    std::vector<std::shared_ptr<Card>> hands;

public:
    Player(const int& ordinal);
    std::string get_playerOrdinal() const;
    void name_himself(const std::string& playerName);
    void exchange_hands(Player& other);
    virtual Card show_card() = 0;
    void draw_card(Deck& deck);
};

#endif