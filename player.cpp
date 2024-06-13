#include "player.hpp"
#include "board.hpp"

namespace ariel {
    void placeSettlement(std::vector<std::string> places, std::vector<int> placesNum, Board board) {
        // Check if the place is valid and available on the board
        if (board.isPlaceAvailableForSettlement(place)) {
            settlements.push_back(place);
        } else {
            throw std::runtime_error("Cannot place a settlement at this location");
        }
    }

    void Player::placeRoad(const std::string& place, Board& board) {
        // Check if the place is valid and available on the board
        if (board.isPlaceAvailableForRoad(place)) {
            roads.push_back(place);
        } else {
            throw std::runtime_error("Cannot place a road at this location");
        }
    }

    // ... additional methods ...
}