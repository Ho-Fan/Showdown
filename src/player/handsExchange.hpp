#ifndef HANDSEXCHANGE_HPP
#define HANDSEXCHANGE_HPP
#include "../player/player.hpp"
#include <memory>
#include <cstdlib>
#include <iostream>

class HandsExchange
{
private:
    std::shared_ptr<Player> initiatorPlayer;
    std::shared_ptr<Player> PassivePlayer;
    int remainTurns = 3;
public:
    HandsExchange();
    void perform_exchange();
    void revert_exchange();
    void decrement_turns();
};

#endif
