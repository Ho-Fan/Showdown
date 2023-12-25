#include "card.hpp"


Card::Card(Rank r, Suit s) : rank(r), suit(s)
{
	std::cout << "Card build." << std::endl;
}
