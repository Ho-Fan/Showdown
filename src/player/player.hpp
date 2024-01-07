#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "../card/deck.hpp"
#include "../card/card.hpp"
#include "handsExchange.hpp"


class Player
{
protected:
    std::string playerOrdinal;
    std::string name;
    int points = 0;
    std::vector<std::unique_ptr<Card>> hands;
    std::shared_ptr<HandsExchange> handsExchange;
    bool activeExchange = true;

public:
    Player();
    Player(const int& ordinal);
    std::string get_playerOrdinal() const;
    void name_himself(const std::string& playerName);
    void exchange_hands(std::shared_ptr<Player>& otherPlayer);
    virtual std::unique_ptr<Card> show_card() = 0;
    void draw_card(std::unique_ptr<Card>&& card);
    void add_one_point();
    int get_points() const;
    bool can_active_exchage() const;
    bool can_pasive_exchanged();
    void set_active_exchange(bool booling);
};

#endif