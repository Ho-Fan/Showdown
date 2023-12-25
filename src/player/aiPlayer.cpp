#include "aiPlayer.hpp"

AIPlayer::AIPlayer(const int& ordinal) : Player::Player(ordinal)
{
}

AIPlayer::~AIPlayer()
{
}

Card AIPlayer::show_card()
{
    return Card();
}
