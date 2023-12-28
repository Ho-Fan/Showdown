#include "showdown.hpp"
#include <iostream>


ShowDown::ShowDown()
{

}

ShowDown::~ShowDown()
{

}

void ShowDown::step0_join_player()
{   
    std::cout << "==== Step 0: Join players. ====" << "\n" << std::endl;
    char response;
    for (int i = 1; i < 5; i++)
    {
        std::cout << 'P' << i << " join as a real palyer? (y/n)" << std::endl;
        std::cin >> response;
        if (response == 'y' or response == 'Y')
        {
            add_player(std::make_shared<HumanPlayer>(i));
        }
        else
        {
            add_player(std::make_shared<AIPlayer>(i));
        }
        std::cout << players[i - 1]->get_playerOrdinal() << " joined successed!" << "\n" << std::endl;
    }   
}

void ShowDown::step1_namePlayer_and_deckShuffle()
{
    std::cout << "\n\n" << "==== Step 1: Name yourself, and we'll shuffle the cards. ====" << "\n" << std::endl;
    std::string response;
    for (auto& player : players)
    {
        if (typeid(*player) == typeid(AIPlayer))
        {
            std::cout << player->get_playerOrdinal() << " is AIPlayer." << std::endl;
            player->name_himself(player->get_playerOrdinal());
        }
        else
        {
            std::cout << player->get_playerOrdinal() << ", please enter your name." << std::endl;
            std::cin >> response;
            player->name_himself(response);
        }
        std::cout << "\n" << std::endl;
    }

    deck.shuffle_cards();
}

void ShowDown::step2_draw_cards()
{
    for (int i = 0; i < 13; ++i)
    {
        for (std::shared_ptr<Player>& player : players)
        {
            std::unique_ptr<Card> card = deck.deal_card();
            player->draw_card(std::move(card));
        }
    }
}

void ShowDown::add_player(const std::shared_ptr<Player>& player)
{
    players.push_back(player);
}
