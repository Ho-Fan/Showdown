#include "deck.hpp"


Deck::Deck()
{
	for (int suit = static_cast<int>(Suit::Club); suit <= static_cast<int>(Suit::Spade); suit++)
	{
		for (int rank = static_cast<int>(Rank::Two); rank <= static_cast<int>(Rank::Ace); rank++)
		{
			cards.emplace_back(std::make_unique<Card>(static_cast<Rank>(rank), static_cast<Suit>(suit)));
		}
	}
}

void Deck::shuffle_cards()
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::shuffle(cards.begin(), cards.end(), generator);
	std::cout << "Shuffle done." << std::endl;
}

std::unique_ptr<Card> Deck::deal_card()
{
	std::unique_ptr<Card> card = std::move(cards.back());
	cards.pop_back();
	return card;
}
