#include "../player/player.hpp"


Player::Player(const int& ordinal)
{
	playerOrdinal = "P" + std::to_string(ordinal);
}

std::string Player::get_playerOrdinal() const
{
	return playerOrdinal;
}

void Player::name_himself(const std::string& playerName)
{
	name = playerName;
	std::cout << "Name " << name << " successed!" << std::endl;
}

void Player::exchange_hands(Player& other)
{
}

void Player::draw_card(std::unique_ptr<Card>&& card)
{
	hands.emplace_back(std::move(card));
}

void Player::add_one_point()
{
	points++;
}

int Player::get_points() const
{
	return points;
}
