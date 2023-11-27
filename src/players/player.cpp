#include <cstdlib>
#include <vector>
#include <string>
#include "card.cpp"

class Player {
protected:
    std::vector<Card> hand;
    int points;
    std::string name;

public:
    void nameHimself(const std::string& name);
    virtual Card show() = 0; // Pure virtual function for polymorphism
    void drawCard(Deck& deck);
    void exchangeHands(Player& other);
};