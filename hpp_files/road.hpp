// maorw9@gmail.com
// 212305965

#ifndef ROAD_HPP
#define ROAD_HPP

#include <iostream>
#include <set>
#include <string>
#include "tile.hpp"

using namespace std;

namespace ariel
{

    class Road
    {
    private:
        string name_of_owner;
        set<Tile> nearby_areas;

    public:
        Road(string name_of_owner, Tile _tile1, Tile _tile2);
        const std::set<Tile> &get_near_by_areas() const;
        bool operator==(const Road &_other) const;
        bool operator<(const Road &_other) const;
        friend std::ostream &operator<<(std::ostream &_os, const Road &_road);
    };

}

#endif // ROAD_HPP