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
public:
    Rank rank;
    Suit suit;

    Card(Rank r, Suit s);
    void print_card_info();
    std::string get_rank();
    std::string get_suit();
};
#endif