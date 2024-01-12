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
    std::cout << "Show one of your cards. (Input the number of the card.)" << std::endl;
    for (std::unique_ptr<Card>& card : hands)
    {
        std::cout << ord++ << ". " << card->get_card_info() << std::endl;
    }
    int response;    
    while (!(std::cin >> response) || (response >= hands.size() || response < 0))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please in put the number of the card." << std::endl;
    }

    std::unique_ptr<Card> card = std::move(hands[response]);
    hands.erase(hands.begin() + response);
    return card;
}
