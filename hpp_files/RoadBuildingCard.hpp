// maorw9@gmail.com
// 212305965

#ifndef ROADBUILDINGCARD_HPP
#define ROADBUILDINGCARD_HPP

#include <vector>
#include <string>
#include "developmentCard.hpp"
#include "player.hpp"
#include "board.hpp"

namespace ariel
{

    class Player;
    class Board;

    class RoadBuildingCard : public DevelopmentCard
    {
    public:
        void play(Player &_player, std::vector<std::string> _places1, std::vector<int> places_num1, std::vector<std::string> _places2, std::vector<int> places_num2, Board &_board);
    };

}

#endif // ROADBUILDINGCARD_HPP
