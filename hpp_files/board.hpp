// maorw9@gmail.com
// 212305965

#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include "tile.hpp"
#include "settlement.hpp"
#include "city.hpp"
#include "road.hpp"

using namespace std;

namespace ariel
{
    class Board
    {
    private:
        std::vector<Tile> _tiles;
        std::set<Road> _roads;
        std::set<Settlement> _settlements;
        std::set<City> _cities;

    public:
        Board();
        std::vector<Tile> &get_tiles();
        std::set<Road> &get_roads();
        std::set<Settlement> &get_settlements();
        std::set<City> &get_cities();
        Board &operator=(const Board &other);
        bool is_possible_road(const Road &road) const;
        bool is_possible_settlement(const Settlement &settlement, const City &city) const;
    };
}

#endif // BOARD_HPP