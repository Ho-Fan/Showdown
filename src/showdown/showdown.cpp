#include "showdown.hpp"
#include <iostream>


ShowDown::ShowDown()
{

}
ShowDown::~ShowDown()
{

}
void ShowDown::flow_join_player()
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
void ShowDown::add_player(const std::shared_ptr<Player>& player)
{
    players.push_back(player);
}
