// maorw9@gmail.com
// 212305965

#include "../hpp_files/board.hpp"
#include <array>

namespace ariel
{

    Board::Board() : _tiles(19)
    {

        _tiles[0] = {"Mountains", 5};
        _tiles[1] = {"Agricultural Land", 2};
        _tiles[2] = {"Forest", 6};
        _tiles[3] = {"Hills", 10};
        _tiles[4] = {"Forest", 9};
        _tiles[5] = {"Pasture Land", 4};
        _tiles[6] = {"Hills", 3};
        _tiles[7] = {"Pasture Land", 8};
        _tiles[8] = {"Mountains", 11};
        _tiles[9] = {"Desert", 0};
        _tiles[10] = {"Agricultural Land", 5};
        _tiles[11] = {"Forest", 8};
        _tiles[12] = {"Pasture Land", 4};
        _tiles[13] = {"Mountains", 3};
        _tiles[14] = {"Hills", 6};
        _tiles[15] = {"Forest", 10};
        _tiles[16] = {"Agricultural Land", 11};
        _tiles[17] = {"Agricultural Land", 12};
        _tiles[18] = {"Pasture Land", 9};

        _tiles[0].set_near_by_areas({&_tiles[1], &_tiles[3], &_tiles[4]});
        _tiles[1].set_near_by_areas({&_tiles[0], &_tiles[2], &_tiles[4], &_tiles[5]});
        _tiles[2].set_near_by_areas({&_tiles[1], &_tiles[5], &_tiles[6]});
        _tiles[3].set_near_by_areas({&_tiles[0], &_tiles[4], &_tiles[7], &_tiles[8]});
        _tiles[4].set_near_by_areas({&_tiles[0], &_tiles[1], &_tiles[3], &_tiles[5], &_tiles[8], &_tiles[9]});
        _tiles[5].set_near_by_areas({&_tiles[1], &_tiles[2], &_tiles[4], &_tiles[6], &_tiles[9], &_tiles[10]});
        _tiles[6].set_near_by_areas({&_tiles[2], &_tiles[5], &_tiles[10], &_tiles[11]});
        _tiles[7].set_near_by_areas({&_tiles[3], &_tiles[8], &_tiles[12]});
        _tiles[8].set_near_by_areas({&_tiles[3], &_tiles[4], &_tiles[7], &_tiles[9], &_tiles[12], &_tiles[13]});
        _tiles[9].set_near_by_areas({&_tiles[4], &_tiles[5], &_tiles[8], &_tiles[10], &_tiles[13], &_tiles[14]});
        _tiles[10].set_near_by_areas({&_tiles[5], &_tiles[6], &_tiles[9], &_tiles[11], &_tiles[14], &_tiles[15]});
        _tiles[11].set_near_by_areas({&_tiles[6], &_tiles[10], &_tiles[15]});
        _tiles[12].set_near_by_areas({&_tiles[7], &_tiles[8], &_tiles[16]});
        _tiles[13].set_near_by_areas({&_tiles[8], &_tiles[9], &_tiles[16], &_tiles[17]});
        _tiles[14].set_near_by_areas({&_tiles[9], &_tiles[10], &_tiles[17], &_tiles[18]});
        _tiles[15].set_near_by_areas({&_tiles[10], &_tiles[11], &_tiles[18]});
        _tiles[16].set_near_by_areas({&_tiles[12], &_tiles[13], &_tiles[17]});
        _tiles[17].set_near_by_areas({&_tiles[13], &_tiles[14], &_tiles[16], &_tiles[18]});
        _tiles[18].set_near_by_areas({&_tiles[14], &_tiles[15], &_tiles[17]});
    }

    std::vector<Tile> &Board::get_tiles()
    {
        return _tiles;
    }

    std::set<Road> &Board::get_roads()
    {
        return _roads;
    }

    std::set<Settlement> &Board::get_settlements()
    {
        return _settlements;
    }

    std::set<City> &Board::get_cities()
    {
        return _cities;
    }

    bool Board::is_possible_road(const Road &road) const
    {
        for (const auto &road_on_board : _roads)
        {
            if (road == road_on_board)
            {
                return false;
            }
        }
        return true;
    }

    bool have_at_least_two_common_elements(const std::set<Tile> &set1, const std::set<Tile> &set2)
    {
        // Create a vector to store the intersection of the two sets
        std::vector<Tile> intersection;

        // Use std::set_intersection to find the common elements
        std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                              std::back_inserter(intersection));

        // Check if the intersection has at least two elements
        return intersection.size() >= 2;
    }

    bool Board::is_possible_settlement(const Settlement &settlement, const City &city) const
    {
        for (const auto &settlement_on_board : _settlements)
        {
            if (settlement == settlement_on_board)
            {
                return false;
            }
        }
        for (const auto &city_on_board : _cities)
        {
            if (city == city_on_board)
            {
                return false;
            }
        }

        std::set<Tile> set1 = settlement.get_near_by_areas();
        std::set<Tile> set2;

        for (const auto &settlement_on_board : _settlements)
        {
            set2 = settlement_on_board.get_near_by_areas();
            if (have_at_least_two_common_elements(set1, set2))
            {
                return false;
            }
        }

        return true;
    }

    Board &Board::operator=(const Board &other)
    {
        if (this != &other)
        {
            _tiles = other._tiles;
            _roads = other._roads;
            _settlements = other._settlements;
        }
        return *this;
    }
}