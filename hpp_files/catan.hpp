// maorw9@gmail.com
// 212305965

#ifndef CATAN_H
#define CATAN_H

#include <iostream>
#include "knightCard.hpp"
#include "MonopolyCard.hpp"
#include "RoadBuildingCard.hpp"
#include "YearOfPlentyCard.hpp"
#include "player.hpp"
#include "board.hpp"
#include <ctime>

namespace ariel
{

    class Catan
    {
    private:
        Player &_p1;
        Player &_p2;
        Player &_p3;
        Player *curr_player;
        Board _board;

    public:
        Catan(Player &_p1, Player &_p2, Player &_p3);
        Board &get_board();
        void roll_dice(Player &_player);
        void end_turn(Player &_player);
        void trade(Player &_p1, Player &_p2, std::string _resource1, std::string _resource2, int _num1, int _num2);
        void player_development_card(Player &_player, std::string _resource);
        void player_development_card(Player &_player, std::vector<std::string> _places1, std::vector<int> places_num1, std::vector<std::string> _places2, std::vector<int> places_num2, Board &_board);
        void player_development_card(Player &_player, const std::string &_resource1, const std::string &_resource2);
        void player_development_card(Player &_player);
        void print_winner();
    };

}

#endif // CATAN_H