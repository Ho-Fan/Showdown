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
    HandsExchange(std::shared_ptr<Player>& inP, std::shared_ptr<Player>& paP);
    ~HandsExchange();
    void decrement_turns();
    int get_remain_turns() const;
};

#endif
