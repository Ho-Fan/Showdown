#ifndef HUMANPLAYER_HPP
#define HUMANPLAYER_HPP
#include "../player/player.hpp"
#include <string>



class HumanPlayer : public Player
{
private:
    /* data */
public:
    HumanPlayer(const int& ordinal);
    ~HumanPlayer();
    Card show_card() override;
};

#endif