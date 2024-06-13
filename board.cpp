#include "board.hpp"
#include <map>
#include <stdexcept>

namespace ariel
{
    const int resourceLimit = 3;
    std::map<string, int> resourceCounts;

    void Board::addTile(int x, int y, Tile tile) {
        // Check if the resource type already exists in the map
        if (resourceCounts.find(tile.resourceType) != resourceCounts.end()) {
            // If the resource type exists, check if adding another would exceed the limit
            if (resourceCounts[tile.resourceType] >= resourceLimit) {
                throw std::runtime_error("Resource limit exceeded");
            }
        }
        // If the board size is not large enough to accommodate the new tile, resize it
        if (x >= board.size() || y >= board[0].size()) {
            board.resize(std::max(x + 1, (int)board.size()));
            for (auto &row : board) {
                row.resize(std::max(y + 1, (int)row.size()));
            }
        }
        // Add the tile to the board and increment the count for its resource type
        board[x][y] = tile;
        resourceCounts[tile.resourceType]++;
    }
}