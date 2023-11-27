#include <iostream>

class Card
{

};

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
    // ... other ranks
    Ace = 14
};