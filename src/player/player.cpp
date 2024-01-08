#include "../player/player.hpp"


Player::Player()
{
}

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

void Player::set_hands_exchange(std::shared_ptr<HandsExchange>& exchange)
{
	handsExchange = exchange;
}

void Player::exchange_hands(std::shared_ptr<Player>& otherPlayer)
{
	activeExchange = false;
	std::swap(hands, otherPlayer->hands);
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

bool Player::can_active_exchage() const
{
	return activeExchange;
}

bool Player::can_pasive_exchanged()
{
	if (handsExchange)
		return false;
	else
		return true;
}

void Player::reset_hands_exchange()
{
	handsExchange.reset();
}
