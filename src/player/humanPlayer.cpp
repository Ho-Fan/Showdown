#include "humanPlayer.hpp"


HumanPlayer::HumanPlayer(const int& ordinal) : Player::Player(ordinal)
{
}

HumanPlayer::~HumanPlayer()
{
}

Card HumanPlayer::show_card()
{
    return Card();
}
