#include "card.hpp"


Card::Card(Rank r, Suit s) : rank(r), suit(s)
{
}

std::string Card::get_card_info()
{
	return get_suit_info() + " " + get_rank_info();
}

Suit Card::get_suit() const
{
	return suit;
}

Rank Card::get_rank() const
{
	return rank;
}

std::string Card::get_rank_info()
{
	switch (rank)
	{
	case Rank::Two:
		return "Two";
	case Rank::Three:
		return "Three";
	case Rank::Four:
		return "Four";
	case Rank::Five:
		return "Five";
	case Rank::Six:
		return "Six";
	case Rank::Seven:
		return "Seven";
	case Rank::Eight:
		return "Eight";
	case Rank::Nine:
		return "Nine";
	case Rank::Ten:
		return "Ten";
	case Rank::Jack:
		return "Jack";
	case Rank::Queen:
		return "Queen";
	case Rank::King:
		return "King";
	case Rank::Ace:
		return "Ace";
	default:
		return "Unknown";
	}
}

std::string Card::get_suit_info()
{
	switch (suit)
	{
	case Suit::Club:
		return "Club";
	case Suit::Diamond:
		return "Diamand";
	case Suit::Heart:
		return "Heart";
	case Suit::Spade:
		return "Spade";
	default:
		return "Unknown";
	}
}