#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

namespace ariel
{
    struct Tile
    {
        string resourceType; //  brick,  Wood,  Sheep, Grain, Iron, Desert
        int numberToken;     // the number token on the tile, 0 for desert
        static const int Desert = 0;
        static const int Brick = 0;
        static const int Wood = 0;
        static const int Sheep = 0;
        static const int Grain = 0;
        static const int Iron = 0;
    };

    class Board
    {

    private:
        std::vector<std::vector<Tile>> board;
        std::vector<std::vector<std::string>> settlements;
        // Define any necessary constants here

        // Define any required data structures here

        // Declare any function prototypes here

    public:
        // Constructor
        Board();

        // Destructor
        // ~Board();

        // Function declarations
        void placeSettlement(std::vector<std::string> places, std::vector<int> placesNum);
        void placeRoad(std::vector<std::string> places, std::vector<int> placesNum);
        void printBoard();
    };


}
#endif // BOARD_HPP