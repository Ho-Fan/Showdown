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
    show_down.flow0_join_player();
    show_down.flow1_namePlayer_and_deckShuffle();
    return 0;
}

