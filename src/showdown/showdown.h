#include <cstdlib>
#include <vector>
#include <memory>
#include "players/player.h"
#include "players/aiPlayer.h"
#include "players/humanPlayer.h"

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
