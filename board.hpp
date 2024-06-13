#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <string>
#include <map>
#include <stdio.h>

namespace ariel
{
    struct Tile
    {
        std::string resourceType; //  brick,  Wood,  Sheep, Wheat, Iron, Desert
        int prob;                 // the number token on the tile, 0 for desert
    };

    class Board
    {

    private:
        std::vector<Tile> board;
        std::vector<std::vector<std::string>> settlements;
        // Define any necessary constants here

        // Define any required data structures here

        // Declare any function prototypes here

    public:
        // Constructor
        Board();
        void printBoard() const;
        bool isPlaceAvailableForSettlement(const std::string &place);
        bool isPlaceAvailableForRoad(const std::string &place);
    };

}
#endif // BOARD_HPP