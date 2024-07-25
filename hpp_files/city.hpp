// maorw9@gmail.com
// 212305965

#ifndef CITY_HPP
#define CITY_HPP

#include <iostream>
#include <set>
#include "tile.hpp"

using namespace std;

namespace ariel
{

    class City
    {
    private:
        string name_of_owner;
        set<Tile> near_by_areas;

    public:
        City(string name_of_owner, Tile _tile1, Tile _tile2, Tile _tile3);
        const std::set<Tile> &get_near_by_areas() const;
        bool operator==(const City &other) const;
        bool operator<(const City &other) const;
        friend std::ostream &operator<<(std::ostream &_os, const City &_city);
    };

}

#endif
