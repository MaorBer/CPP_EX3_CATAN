// maorw9@gmail.com
// 212305965

#include "../hpp_files/board.hpp"
#include <array>

namespace ariel
{
    /**
     * @brief Default constructor for the Board class.
     * Initializes the board with predefined tiles and their adjacent tiles.
     */
    Board::Board() : _tiles(19)
    {
        // Initializing tiles with predefined terrain types and numbers
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

        // Setting adjacent tiles for each tile
        _tiles[0].adjacent_tiles({&_tiles[1], &_tiles[3], &_tiles[4]});
        _tiles[1].adjacent_tiles({&_tiles[0], &_tiles[2], &_tiles[4], &_tiles[5]});
        _tiles[2].adjacent_tiles({&_tiles[1], &_tiles[5], &_tiles[6]});
        _tiles[3].adjacent_tiles({&_tiles[0], &_tiles[4], &_tiles[7], &_tiles[8]});
        _tiles[4].adjacent_tiles({&_tiles[0], &_tiles[1], &_tiles[3], &_tiles[5], &_tiles[8], &_tiles[9]});
        _tiles[5].adjacent_tiles({&_tiles[1], &_tiles[2], &_tiles[4], &_tiles[6], &_tiles[9], &_tiles[10]});
        _tiles[6].adjacent_tiles({&_tiles[2], &_tiles[5], &_tiles[10], &_tiles[11]});
        _tiles[7].adjacent_tiles({&_tiles[3], &_tiles[8], &_tiles[12]});
        _tiles[8].adjacent_tiles({&_tiles[3], &_tiles[4], &_tiles[7], &_tiles[9], &_tiles[12], &_tiles[13]});
        _tiles[9].adjacent_tiles({&_tiles[4], &_tiles[5], &_tiles[8], &_tiles[10], &_tiles[13], &_tiles[14]});
        _tiles[10].adjacent_tiles({&_tiles[5], &_tiles[6], &_tiles[9], &_tiles[11], &_tiles[14], &_tiles[15]});
        _tiles[11].adjacent_tiles({&_tiles[6], &_tiles[10], &_tiles[15]});
        _tiles[12].adjacent_tiles({&_tiles[7], &_tiles[8], &_tiles[16]});
        _tiles[13].adjacent_tiles({&_tiles[8], &_tiles[9], &_tiles[16], &_tiles[17]});
        _tiles[14].adjacent_tiles({&_tiles[9], &_tiles[10], &_tiles[17], &_tiles[18]});
        _tiles[15].adjacent_tiles({&_tiles[10], &_tiles[11], &_tiles[18]});
        _tiles[16].adjacent_tiles({&_tiles[12], &_tiles[13], &_tiles[17]});
        _tiles[17].adjacent_tiles({&_tiles[13], &_tiles[14], &_tiles[16], &_tiles[18]});
        _tiles[18].adjacent_tiles({&_tiles[14], &_tiles[15], &_tiles[17]});
    }

    /**
     * @brief Get the tiles on the board.
     * @return Reference to the vector of tiles.
     */
    std::vector<Tile> &Board::get_tiles()
    {
        return _tiles;
    }

    /**
     * @brief Get the roads on the board.
     * @return Reference to the set of roads.
     */
    std::set<Road> &Board::get_roads()
    {
        return _roads;
    }

    /**
     * @brief Get the settlements on the board.
     * @return Reference to the set of settlements.
     */
    std::set<Settlement> &Board::get_settlements()
    {
        return _settlements;
    }

    /**
     * @brief Get the cities on the board.
     * @return Reference to the set of cities.
     */
    std::set<City> &Board::get_cities()
    {
        return _cities;
    }

    /**
     * @brief Check if placing a road is possible.
     * @param road The road to be placed.
     * @return True if the road can be placed, false otherwise.
     */
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

    /**
     * @brief Check if two sets of tiles have at least two common elements.
     * @param set1 The first set of tiles.
     * @param set2 The second set of tiles.
     * @return True if there are at least two common elements, false otherwise.
     */
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

    /**
     * @brief Check if placing a settlement is possible.
     * @param settlement The settlement to be placed.
     * @param city The city to be placed.
     * @return True if the settlement can be placed, false otherwise.
     */
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

    /**
     * @brief Assignment operator for the Board class.
     * @param other The other board to copy from.
     * @return Reference to the current board.
     */
    Board &Board::operator=(const Board &other)
    {
        if (this != &other)
        {
            _tiles = other._tiles;
            _roads = other._roads;
            _settlements = other._settlements;
            _cities = other._cities;
        }
        return *this;
    }
}
