#include <cstdlib>
#include <iostream>
#include <memory>
#include "showdown/showdown.hpp"
#include "player/aiPlayer.hpp"
#include "player/humanPlayer.hpp"
#include "card/deck.hpp"

int main()
{
    ShowDown show_down;
    show_down.flow_join_player();
    return 0;
}

