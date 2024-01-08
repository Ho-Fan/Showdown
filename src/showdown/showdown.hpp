#ifndef SHOWDOWN_HPP
#define SHOWDOWN_HPP
#include <cstdlib>
#include <vector>
#include <memory>
#include "../player/player.hpp"
#include "../player/aiPlayer.hpp"
#include "../player/humanPlayer.hpp"
#include "../player/handsExchange.hpp"



class ShowDown
{
private:
    std::vector<std::shared_ptr<Player>> players;
    Deck deck;
    std::vector<std::shared_ptr<HandsExchange>> allExchanges;
public:
    ShowDown();
    ~ShowDown();
    void step0_join_player();
    void stepA_namePlayer_and_deckShuffle();
    void stepB_draw_cards();
    void stepC_execute_rounds();

    void add_player(const std::shared_ptr<Player>& player);
    void perform_exchange_hands(std::shared_ptr<Player>& player);
    void rank_card(std::vector<std::unique_ptr<Card>>& roundCards);
    void announce_winner();
    void decrement_all_exchange_turns();
    void terminate_expired_exchange_hands();
};

#endif
