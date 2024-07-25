// maorw9@gmail.com
// 212305965

#include "../hpp_files/tile.hpp"

namespace ariel
{

    Tile::Tile() : _terrain(""), _number(0) {}

    Tile::Tile(const std::string &_terrain, int _number) : _terrain(_terrain), _number(_number) {}

    Tile::Tile(const Tile &_other) : _terrain(_other._terrain), _number(_other._number)
    {
        for (auto _tile : _other.near_by_areas)
        {
            near_by_areas.insert(_tile);
        }
    }

    std::string Tile::get_terrain() const
    {
        return _terrain;
    }

    int Tile::get_number() const
    {
        return _number;
    }

    void Tile::set_terrain(const std::string &_terrain)
    {
        this->_terrain = _terrain;
    }

    void Tile::set_number(int _number)
    {
        this->_number = _number;
    }

    const std::set<Tile *> &Tile::get_near_by_areas() const
    {
        return this->near_by_areas;
    }

    void Tile::set_near_by_areas(const std::initializer_list<Tile *> &near_by_tiles)
    {
        near_by_areas.clear();
        for (Tile *tile : near_by_tiles)
        {
            near_by_areas.insert(tile);
        }
    }

    Tile &Tile::operator=(const Tile &_other)
    {
        if (this != &_other)
        {
            _terrain = _other._terrain;
            _number = _other._number;
            near_by_areas.clear();
            for (auto _tile : _other.near_by_areas)
            {
                near_by_areas.insert(_tile);
            }
        }
        return *this;
    }

    bool Tile::operator==(const Tile &_other) const
    {
        if (this->_terrain.empty() || _other._terrain.empty())
        {
            return false;
        }
        return this->_terrain == _other._terrain && this->_number == _other._number;
    }

    bool Tile::operator!=(const Tile &_other) const
    {
        return !(*this == _other);
    }

    bool Tile::operator<(const Tile &_other) const
    {
        if (_terrain == _other._terrain)
        {
            return _number < _other._number;
        }
        return _terrain < _other._terrain;
    }

    std::ostream &operator<<(std::ostream &_os, const Tile &_tile)
    {
        _os << "Tile(terrain: " << _tile._terrain << ", number: " << _tile._number << ".";
        return _os;
    }
}