#ifndef HUMANPLAYER_HPP
#define HUMANPLAYER_HPP
#include "../player/player.hpp"



class HumanPlayer : public Player
{
private:
    /* data */
public:
    HumanPlayer(/* args */);
    ~HumanPlayer();
    Card show_card() override;
};

#endif