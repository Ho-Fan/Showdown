#include "showdown.hpp"

ShowDown::ShowDown()
{
    
}
ShowDown::~ShowDown()
{
    
}
void ShowDown::add_player(const std::shared_ptr<Player>& player)
{
    players.push_back(player);
}
