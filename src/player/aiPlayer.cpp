#include "aiPlayer.hpp"

AIPlayer::AIPlayer(const int& ordinal) : Player::Player(ordinal)
{
}

AIPlayer::~AIPlayer()
{
}

std::unique_ptr<Card> AIPlayer::show_card()
{
    std::unique_ptr<Card> card = std::move(hands.back());
    hands.pop_back();
    return card;
}
