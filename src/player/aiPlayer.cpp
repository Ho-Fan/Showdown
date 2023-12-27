#include "aiPlayer.hpp"

AIPlayer::AIPlayer(const int& ordinal) : Player::Player(ordinal)
{
}

AIPlayer::~AIPlayer()
{
}

std::unique_ptr<Card> AIPlayer::show_card()
{
    return 0;
}
