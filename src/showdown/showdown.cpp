#include "showdown.hpp"
#include <iostream>


ShowDown::ShowDown()
{

}


ShowDown::~ShowDown()
{

}


void ShowDown::step0_join_player()
{   
    std::cout << "==== Step 0: Join players. ====" << "\n" << std::endl;
    char response;
    for (int i = 1; i < 5; i++)
    {
        std::cout << 'P' << i << " join as a real player? (y/n)" << std::endl;
        std::cin >> response;
        if (response == 'y' or response == 'Y')
        {
            add_player(std::make_shared<HumanPlayer>(i));
        }
        else
        {
            add_player(std::make_shared<AIPlayer>(i));
        }
        std::cout << players[i - 1]->get_playerOrdinal() << " joined successed!" << "\n" << std::endl;
    }   
}


void ShowDown::stepA_namePlayer_and_deckShuffle()
{
    std::cout << "\n\n" << "==== Step 1: Name yourself, and we'll shuffle the cards. ====" << "\n" << std::endl;
    std::string response;
    for (auto& player : players)
    {
        if (typeid(*player) == typeid(AIPlayer))
        {
            std::cout << player->get_playerOrdinal() << " is AIPlayer." << std::endl;
            player->name_himself(player->get_playerOrdinal());
        }
        else
        {
            std::cout << player->get_playerOrdinal() << ", please enter your name." << std::endl;
            std::cin >> response;
            player->name_himself(response);
        }
        std::cout << "\n" << std::endl;
    }
    deck.shuffle_cards();
}


void ShowDown::stepB_draw_cards()
{
    std::cout << "\n\n" << "=== Step 2: Draw cards. ===" << std::endl;
    for (int i = 0; i < 13; ++i)
    {
        for (std::shared_ptr<Player>& player : players)
        {
            std::unique_ptr<Card> card = deck.deal_card();
            player->draw_card(std::move(card));
        }
    }
    std::cout << "Draw cards done." << std::endl;
}


void ShowDown::stepC_execute_rounds()
{
    std::cout << "\n\n" << "=== Step 3: Game start!!! ===" << std::endl;
    std::vector<std::unique_ptr<Card>> roundCards;
    for (int round = 1; round < 14; ++round)
    {
        std::cout << "\n\n\n" << "--- Round " << round <<  " ---\n" << std::endl;
        for (auto& player : players)
        {
            // If the player have no card in hands, push back a nullptr and skip turn.
            if (player->get_size_of_hands() == 0)
            {
                roundCards.emplace_back(nullptr);
                continue;
            }

            std::cout << "--- " << player->get_playerOrdinal() << " turn." << " ---" << std::endl;
            if (typeid(*player) == typeid(HumanPlayer) && player->can_active_exchage() == true && player->can_pasive_exchanged() == true)
            {
                perform_exchange_hands(player);
            }
            std::cout << "\n" << std::endl;
            std::unique_ptr<Card> card = std::move(player->show_card());
            roundCards.emplace_back(std::move(card));
            std::cout << "\n" << std::endl;
        }
        for (int i = 0; i < 4; i++)
        {
            std::cout << "P" << i + 1 << " show card " << roundCards[i]->get_card_info() << "." << std::endl;
        }
        rank_card(roundCards);

        decrement_all_exchange_turns();
        terminate_expired_exchange_hands();
    }
    announce_winner();
}


void ShowDown::add_player(const std::shared_ptr<Player>& player)
{
    players.push_back(player);
}


void ShowDown::perform_exchange_hands(std::shared_ptr<Player>& activePlayer)
{
    std::cout << "Do you want to exchange hands with someone? (y/n)" << std::endl;
    char response;
    std::cin >> response;
    while ((response != 'y' && response != 'Y') && (response != 'n' && response != 'N'))
    {
        std::cout << "Invalid response. Please enter 'y' or 'n': " << std::endl;
        std::cin >> response;
    }

    if (response == 'y' || response == 'Y')
    {
        std::vector<std::shared_ptr<Player>> availablePasivePlayers;
        for (auto& player : players)
        {
            if (player != activePlayer && player->can_pasive_exchanged() == true)
                availablePasivePlayers.emplace_back(player);
        }
        int responseOrdinal = -1;
        while (responseOrdinal < 0 || responseOrdinal >= availablePasivePlayers.size())
        {
            std::cout << "You can exchange hands with the players below." << std::endl;
            for (int i = 0; i < availablePasivePlayers.size(); ++i)
            {
                std::cout << i << ". " << availablePasivePlayers[i]->get_playerOrdinal() << std::endl;
            }
            std::cout << "\n" << "Which player do you want to change with?" << std::endl;
            std::cin >> responseOrdinal;
        }

        std::shared_ptr<Player> passivePlayer = availablePasivePlayers[responseOrdinal];
        allExchanges.emplace_back(std::make_shared<HandsExchange>(activePlayer, passivePlayer));
        activePlayer->set_hands_exchange(allExchanges.back());
        passivePlayer->set_hands_exchange(allExchanges.back());
        activePlayer->exchange_hands(passivePlayer);
        std::cout << "You have exchanged hands with " << passivePlayer->get_playerOrdinal() << "!!!" << std::endl;
    }
}


void ShowDown::rank_card(std::vector <std::unique_ptr<Card>>& roundCards)
{
    // Define lambda function "compare" for max_element method
    auto compare = [](const std::unique_ptr<Card>& a, const std::unique_ptr<Card>& b)
        {
            // Deal with the nullptr. If a is null, return b > a.
            if (!a)
                return false;
            // Deal with the nullptr. If b is null, return a > b.
            if (!b)
                return true;
            // If card != nullptr, rank card normally.
            if (a->get_rank() == b->get_rank())
            {
                return a->get_suit() < b->get_suit();
            }
            else
            {
                return a->get_rank() < b->get_rank();
            }
        };

    // Find the max element
    auto it = std::max_element(roundCards.begin(), roundCards.end(), compare);
    // Get ordinal of the max element
    auto ordinal = std::distance(roundCards.begin(), it);
    // Announce the winner of this round
    std::cout << "P" << ordinal + 1 << " show the max card, " << roundCards[ordinal]->get_card_info() << ". He/She win the round!!!" << std::endl;
    // Add one point for the winner
    players[ordinal]->add_one_point();
    // Clear the vector "roundCards" 
    roundCards.clear();
}


void ShowDown::announce_winner()
{
    for (const std::shared_ptr<Player>& player : players)
        std::cout << player->get_playerOrdinal() << " get " << player->get_points() << " points." << std::endl;
    // Define lambda function "compare" for max element function
    auto compare = [](const std::shared_ptr<Player>& a, const std::shared_ptr<Player>& b)
        {
            return a->get_points() < b->get_points();
        };
    // Find the max element
    auto it = std::max_element(players.begin(), players.end(), compare);
    int max_points = (*it)->get_points();
    // Announce the winners
    std::cout << "\n" << "The winner is ";
    for (const std::shared_ptr<Player>& player : players)
    {
        if (player->get_points() == max_points)
            std::cout << player->get_playerOrdinal() << " ";
    }
    std::cout << "!!!" << std::endl;
}

void ShowDown::decrement_all_exchange_turns()
{
    for (auto& exchange : allExchanges)
        exchange->decrement_turns();
}

void ShowDown::terminate_expired_exchange_hands()
{
    for (int i = 0; i < allExchanges.size(); i++)
    {
        if (allExchanges[i]->get_remain_turns() <= 0)
        {
            allExchanges[i]->terminate_hands_exchange();
            allExchanges.erase(allExchanges.begin() + i);
        }
    }
}