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
    show_down.step0_join_player();
    show_down.stepA_namePlayer_and_deckShuffle();
    show_down.stepB_draw_cards();
    show_down.stepC_execute_rounds();
    return 0;
}

