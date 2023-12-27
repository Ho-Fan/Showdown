#ifndef AIPLAYER_HPP
#define AIPLAYER_HPP
#include "../player/player.hpp"



class AIPlayer : public Player
{
private:
    /* data */
public:
    AIPlayer(const int& ordinal);
    ~AIPlayer();
    std::unique_ptr<Card> show_card() override;
};

#endif

