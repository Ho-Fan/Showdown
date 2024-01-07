#ifndef HANDSEXCHANGE_HPP
#define HANDSEXCHANGE_HPP
#include <memory>
#include <cstdlib>
#include <iostream>

class Player; // Forward declaration

class HandsExchange
{
private:
    std::shared_ptr<Player> initiatorPlayer;
    std::shared_ptr<Player> passivePlayer;
    int remainTurns = 3;

public:
    HandsExchange();
    void perform_exchange();
    void revert_exchange();
    void decrement_turns();
};

#endif
