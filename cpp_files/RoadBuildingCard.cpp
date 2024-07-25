// maorw9@gmail.com
// 212305965

#include "../hpp_files/RoadBuildingCard.hpp"

namespace ariel
{

    void RoadBuildingCard::play(Player &_player, std::vector<std::string> _places1, std::vector<int> places_num1, std::vector<std::string> _places2, std::vector<int> places_num2, Board &_board)
    {
        _player.set_bricks(_player.get_bricks() + 2);
        _player.set_wood(_player.get_wood() + 2);
        _player.place_road(_places1, places_num1, _board);
        _player.place_road(_places2, places_num2, _board);
        std::cout << "Road Building card played by " << _player.get_name() << ": You can build two roads without cost." << std::endl;
    }

}