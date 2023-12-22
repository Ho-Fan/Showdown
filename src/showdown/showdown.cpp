#include "showdown.hpp"
#include <iostream>


ShowDown::ShowDown()
{

}

ShowDown::~ShowDown()
{

}

void ShowDown::flow0_join_player()
{
    char response;
    for (int i = 1; i < 5; i++)
    {
        std::cout << 'P' << i << " join as a real palyer? (y/n)" << std::endl;
        std::cin >> response;
        if (response == 'y' or response == 'Y')
        {
            add_player(std::make_shared<HumanPlayer>());
        }
        else
        {
            add_player(std::make_shared<AIPlayer>());
        }
        std::cout << 'P' << i << " joined successed!" << "\n" << std::endl;
    }   
}

void ShowDown::flow1_namePlayer_and_deckShuffle()
{
    std::cout << "\n" << "Please name yourself!" << std::endl;
    for (int i = 1; i < 4; i++)
    {
        std::cout << "\nPlease enter your name, " << 'P' << i << '.' << std::endl;
        std::string response;
        std::cin >> response;
        players[i - 1]->name_himself(response);
        std::cout << "P" << i - 1 << " is named " << players[i - 1]->name << 
    }
}

void ShowDown::add_player(const std::shared_ptr<Player>& player)
{
    players.push_back(player);
}
