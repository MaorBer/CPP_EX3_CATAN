// maorw9@gmail.com
// 212305965

#include "../hpp_files/knightCard.hpp"

namespace ariel
{

    Tile *KnightCard::_knight = new Tile("NoTerrain", 0);
    Tile *KnightCard::get_knight()
    {
        return _knight;
    }

    void KnightCard::set_knight(const std::string &_terrain, int _number)
    {
        if (_knight == nullptr)
        {
            _knight = new Tile(_terrain, _number);
        }
        else
        {
            _knight->set_terrain(_terrain);
            _knight->set_number(_number);
        }
    }

    void KnightCard::play(Player &_player)
    {
        string _terrain;
        int _num;
        std::cout << "Enter a resource and a number of a tile you want to put the knight on (e.g., Agricultural Land 4): ";
        std::cin >> _terrain >> _num;
        Tile knight(_terrain, _num);
        this->_knight = &knight;
        std::cout << "Knight card played by " << _player.get_name() << ": Move the robber to tile with " << _terrain << " and number " << _num << std::endl;
    }

}