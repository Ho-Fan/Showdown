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
    for (int i = 0; i < 4; i++)
        std::cout << "Join as a real palyer? (y/n)" << std::endl;
}
void ShowDown::add_player(const std::shared_ptr<Player>& player)
{
    players.push_back(player);
}
