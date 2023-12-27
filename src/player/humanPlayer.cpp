#include "humanPlayer.hpp"


HumanPlayer::HumanPlayer(const int& ordinal) : Player::Player(ordinal)
{
}

HumanPlayer::~HumanPlayer()
{
}

std::unique_ptr<Card> HumanPlayer::show_card()
{
    return 0;
}
