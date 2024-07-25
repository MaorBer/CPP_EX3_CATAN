// maorw9@gmail.com
// 212305965

#include "../hpp_files/road.hpp"

namespace ariel
{

    Road::Road(string name_of_owner, Tile _tile1, Tile _tile2)
    {
        this->nearby_areas.insert(_tile1);
        this->nearby_areas.insert(_tile2);
        this->name_of_owner = name_of_owner;
    }

    const std::set<Tile> &Road::get_near_by_areas() const
    {
        return this->nearby_areas;
    }

    bool Road::operator==(const Road &_other) const
    {
        if (this->name_of_owner != _other.name_of_owner)
        {
            return false;
        }

        auto _it1 = this->nearby_areas.begin();
        auto _it2 = _other.nearby_areas.begin();
        for (; _it1 != this->nearby_areas.end() && _it2 != _other.nearby_areas.end(); ++_it1, ++_it2)
        {
            if (*_it1 != *_it2)
            {
                return false;
            }
        }
        return true;
    }

    bool Road::operator<(const Road &_other) const
    {
        if (this->name_of_owner != _other.name_of_owner)
        {
            return this->name_of_owner < _other.name_of_owner;
        }

        auto _it1 = this->nearby_areas.begin();
        auto _it2 = _other.nearby_areas.begin();
        for (; _it1 != this->nearby_areas.end() && _it2 != _other.nearby_areas.end(); ++_it1, ++_it2)
        {
            if (*_it1 != *_it2)
            {
                return *_it1 < *_it2;
            }
        }

        return this->nearby_areas.size() < _other.nearby_areas.size();
    }

    std::ostream &operator<<(std::ostream &_os, const Road &_road)
    {
        _os << "Road(name of owner: " << _road.name_of_owner << ", nearby_areas: [";
        for (const auto &tile : _road.nearby_areas)
        {
            _os << tile << ", ";
        }
        _os << "])";
        return _os;
    }

}
