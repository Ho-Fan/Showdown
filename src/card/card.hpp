#ifndef CARD_HPP
#define CARD_HPP
#include <cstdlib>
#include <iostream>
#include <string>


// Define an enum class for card suits
enum class Suit {
    Club,    // 0
    Diamond, // 1
    Heart,   // 2
    Spade    // 3
};

// Define an enum class for card ranks
enum class Rank {
    Two = 2,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};


class Card {
private:
    Rank rank;
    Suit suit;

    std::string get_suit_info();
    std::string get_rank_info();

public:
    Card(Rank r, Suit s);
    std::string get_card_info();
    Suit get_suit() const;
    Rank get_rank() const;
};
#endif