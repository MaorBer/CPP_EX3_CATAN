#include <iostream>
#include <vector>
#include <string>
#include "board.hpp"


#ifndef PLAYER_HPP
#define PLAYER_HPP


namespace ariel {
    class Player {
        // Add member variables and functions here
        private:
            std::string name;
            std::vector<std::string> resources;
            std::vector<std::string> settlements;
            std::vector<std::string> roads;
            std::vector<std::string> cities;
            std::vector<std::string> dev_cards;
            std::vector<std::string> ports;
        public:
            // Constructor
            Player(std::string player_name);
            
            // Getter functions
            std::string get_name();

            
            // Setter functions
        

            void placeSettelemnt(std::vector<std::string> places, std::vector<int> placesNum, Board board);
            void placeRoad(std::vector<std::string> places, std::vector<int> placesNum, Board board);
            void rollDice();
            void endTurn();
            void trade(Player player, std::string my_resource, std::string your_resource, int my_amount, int your_amount);
            void buyDevelopmentCard();
            void printPoints();

            
            // Other member functions

    };
}


#endif // PLAYER_HPP