#ifndef AIPLAYER_HPP
#define AIPLAYER_HPP
#include "../player/player.hpp"



class AIPlayer : public Player
{
private:
    /* data */
public:
    AIPlayer(/* args */);
    ~AIPlayer();
    Card show_card() override;
};

#endif

