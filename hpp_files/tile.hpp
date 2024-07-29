// maorw9@gmail.com
// 212305965

#ifndef TILE_HPP
#define TILE_HPP

#include <iostream>
#include <string>
#include <set>

namespace ariel
{

    class Tile
    {
    private:
        std::string _terrain;
        int _number;
        std::set<Tile *> near_by_areas;

    public:
        Tile();
        Tile(const std::string &_terrain, int _number);
        Tile(const Tile &_other);
        std::string get_terrain() const;
        int get_number() const;
        void set_terrain(const std::string &_terrain);
        void set_number(int _number);
        const std::set<Tile *> &get_near_by_areas() const;
        void adjacent_tiles(const std::initializer_list<Tile *> &near_by_tiles);
        Tile &operator=(const Tile &_other);
        bool operator==(const Tile &_other) const;
        bool operator!=(const Tile &_other) const;
        bool operator<(const Tile &_other) const;
        friend std::ostream &operator<<(std::ostream &_os, const Tile &_tile);
    };

} // namespace ariel

#endif // TILE_HPP