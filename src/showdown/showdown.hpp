#include <cstdlib>
#include <vector>
#include <memory>
#include "players/player.hpp"
#include "players/aiPlayer.hpp"
#include "players/humanPlayer.hpp"

class ShowDown
{
private:
    std::vector<std::shared_ptr<player>> players;
    Deck deck;
public:
    ShowDown(/* args */);
    ~ShowDown();
    add_players();
};
