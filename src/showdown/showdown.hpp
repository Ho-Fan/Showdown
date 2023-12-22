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
    void flow0_join_player();
    void flow1_namePlayer_and_deckShuffle();
    void add_player(const std::shared_ptr<Player>& player);
};

#endif
