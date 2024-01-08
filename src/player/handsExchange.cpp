#include "handsExchange.hpp"
#include "player.hpp"

HandsExchange::HandsExchange(std::shared_ptr<Player>& inP, std::shared_ptr<Player>& paP) : initiatorPlayer(inP), passivePlayer(paP)
{
}

HandsExchange::~HandsExchange()
{
	initiatorPlayer->exchange_hands(passivePlayer);
	initiatorPlayer->reset_hands_exchange();
	passivePlayer->reset_hands_exchange();
}

void HandsExchange::decrement_turns()
{
	remainTurns--;
}

int HandsExchange::get_remain_turns() const
{
	return remainTurns;
}
