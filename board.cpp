#include "board.hpp"
#include <map>
#include <stdexcept>
#include <algorithm>
#include <random>
#include <iostream>

namespace ariel
{
    // Implementation of the Board class member functions

    // Constructor
    Board::Board()
    {
        // Initialize the resource limits
        std::map<std::string, int> resourceLimits = {
            {"Sheep", 4},
            {"Ore", 3},
            {"Wheat", 4},
            {"Brick", 3},
            {"Wood", 4},
            {"Desert", 1},
        };

        // Initialize the resource counts
        std::map<std::string, int> resourceCounts;

        // Initialize the board with the default tiles
        std::vector<Tile> tiles = {
            {"Sheep", 0},
            {"Sheep", 0},
            {"Sheep", 0},
            {"Sheep", 0},
            {"Ore", 0},
            {"Ore", 0},
            {"Ore", 0},
            {"Wheat", 0},
            {"Wheat", 0},
            {"Wheat", 0},
            {"Wheat", 0},
            {"Brick", 0},
            {"Brick", 0},
            {"Brick", 0},
            {"Wood", 0},
            {"Wood", 0},
            {"Wood", 0},
            {"Wood", 0},
            {"Desert", 0},
        };

        // Use a random device to generate a seed for the random number generator
        std::random_device rd;

        // Use the seed to initialize a default random number generator
        std::default_random_engine rng(rd());

        // Shuffle the tiles
        std::shuffle(tiles.begin(), tiles.end(), rng);

        // The order of numbers to be assigned to the tiles
        std::vector<int> numbers = {5, 2, 6, 3, 8, 10, 9, 12, 11, 4, 8, 10, 9, 4, 5, 6, 3, 11};

        // Assign the numbers to the tiles, skipping the desert
        auto num_iter = numbers.begin();
        for (auto &tile : tiles)
        {
            if (tile.resourceType != "Desert")
            {
                if (num_iter != numbers.end())
                {
                    tile.prob = *num_iter;
                    ++num_iter;
                }
                else
                {
                    throw std::runtime_error("Ran out of numbers to assign to tiles");
                }
            }
        }

        // Add the tiles to the board
        for (const auto &tile : tiles)
        {
            if (resourceCounts[tile.resourceType] >= resourceLimits[tile.resourceType])
            {
                throw std::runtime_error("Resource limit exceeded for " + tile.resourceType);
            }
            resourceCounts[tile.resourceType]++;
            board.push_back(tile);
        }
    }

    void Board::printBoard() const
    {
        for (const auto &tile : board)
        {
            std::cout << "Resource: " << tile.resourceType << ", Number: " << tile.prob << std::endl;
        }
    }

}