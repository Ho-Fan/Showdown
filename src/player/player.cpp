#include "../player/player.hpp"

Player::Player()
{

}

void Player::name_himself(const std::string& playerName)
{
	name = playerName;
	std::cout << name << std::endl;
}

void Player::exchange_hands(Player& other)
{
}

void Player::draw_card(Deck& deck)
{
}
