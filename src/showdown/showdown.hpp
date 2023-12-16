#ifndef SHOWDOWN_HPP
#define SHOWDOWN_HPP
#include <cstdlib>
#include <vector>
#include <memory>
#include "../player/player.hpp"
#include "../player/aiPlayer.hpp"
#include "../player/humanPlayer.hpp"



class ShowDown
{
private:
    std::vector<std::shared_ptr<Player>> players;
    Deck deck;
public:
    ShowDown();
    ~ShowDown();
    void add_player(const std::shared_ptr<Player>& player);
};

#endif