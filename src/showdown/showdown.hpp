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
    void step0_join_player();
    void stepA_namePlayer_and_deckShuffle();
    void stepB_draw_cards();
    void stepC_execute_rounds();

    void add_player(const std::shared_ptr<Player>& player);
    void rank_card(std::vector<std::unique_ptr<Card>>& roundCards);
};

#endif
