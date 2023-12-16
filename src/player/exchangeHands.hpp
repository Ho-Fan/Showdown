#ifndef EXCHANGEHANDS_HPP
#define EXCHANGEHANDS_HPP
#include "../player/player.hpp"


class HandsExchange
{
private:
    Player* player1;
    Player* player2;
    int remaninTurns;
public:
    HandsExchange(Player* player1, Player* player2);
    void perform_exchange();
    void revert_exchange();
    void decrement_turns();
};

#endif