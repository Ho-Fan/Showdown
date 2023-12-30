#include "humanPlayer.hpp"


HumanPlayer::HumanPlayer(const int& ordinal) : Player::Player(ordinal)
{
}

HumanPlayer::~HumanPlayer()
{
}

std::unique_ptr<Card> HumanPlayer::show_card()
{
    int ord = 0;
    for (std::unique_ptr<Card>& card : hands)
    {
        std::cout << ord++ << ". " << card->get_card_info() << std::endl;
    }
    std::cout << "Show one of your cards. (Input the number of the card.)" << std::endl;
    int response;
    std::cin >> response;

    std::unique_ptr<Card> card = std::move(hands[response]);
    hands.erase(hands.begin() + response);
    return card;
}
