// maorw9@gmail.com
// 212305965

#ifndef SETTLEMENT_HPP
#define SETTLEMENT_HPP

#include <iostream>
#include <set>
#include <string>
#include "tile.hpp"

using namespace std;

namespace ariel
{

    class Settlement
    {
    private:
        std::string name_of_owner;
        std::set<Tile> near_by_areas;

    public:
        Settlement(std::string name_of_owner, Tile _tile1, Tile _tile2, Tile _tile3);
        const std::set<Tile> &get_near_by_areas() const;
        bool operator==(const Settlement &_other) const;
        bool operator<(const Settlement &_other) const;
        friend std::ostream &operator<<(std::ostream &_os, const Settlement &_settlement);
    };

}

#endif // SETTLEMENT_HPP
