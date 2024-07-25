// maorw9@gmail.com
// 212305965

#include "../hpp_files/settlement.hpp"

namespace ariel
{

    Settlement::Settlement(std::string name_of_owner, Tile _tile1, Tile _tile2, Tile _tile3)
    {
        this->near_by_areas.insert(_tile1);
        this->near_by_areas.insert(_tile2);
        this->near_by_areas.insert(_tile3);
        this->name_of_owner = name_of_owner;
    }

    const std::set<Tile> &Settlement::get_near_by_areas() const
    {
        return this->near_by_areas;
    }

    bool Settlement::operator==(const Settlement &_other) const
    {
        if (this->near_by_areas.size() != _other.near_by_areas.size())
        {
            return false;
        }

        auto _it1 = this->near_by_areas.begin();
        auto _it2 = _other.near_by_areas.begin();
        while (_it1 != this->near_by_areas.end() && _it2 != _other.near_by_areas.end())
        {
            if (!(*_it1 == *_it2))
            {
                return false;
            }
            ++_it1;
            ++_it2;
        }
        return true;
    }

    bool Settlement::operator<(const Settlement &_other) const
    {
        if (this->name_of_owner != _other.name_of_owner)
        {
            return this->name_of_owner < _other.name_of_owner;
        }
        return this->near_by_areas < _other.near_by_areas;
    }

    std::ostream &operator<<(std::ostream &_os, const Settlement &_settlement)
    {
        _os << "Settlement(name of owner: " << _settlement.name_of_owner << "\n";
        _os << "nearby_areas: [\n";
        for (const auto &tile : _settlement.near_by_areas)
        {
            _os << "  " << tile << ",\n";
        }
        _os << "])\n";
        return _os;
    }
}
