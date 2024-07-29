// maorw9@gmail.com
// 212305965

#include <iostream>
#include <stdexcept>
#include <vector>
#include "hpp_files/catan.hpp"

using namespace std;
using namespace ariel;

int main()
{
    // Initialize players
    Player p1("Liya");
    Player p2("Maor");
    Player p3("Yuval");

    // Initialize the game with the players
    Catan catan(p1, p2, p3);

    // Get the game board reference
    Board& board = catan.get_board();

    // Player 1 places settlements and roads
    vector<string> places = {"Forest", "Mountains", "Hills"};
    vector<int> placesNum = {3, 8, 10};
    p1.place_settelemnt(places, placesNum, board);

    places = {"Forest", "Mountains"};
    placesNum = {3, 8};
    p1.place_road(places, placesNum, board);

    places = {"Agricultural Land", "Hills", "Mountains"};
    placesNum = {12, 6, 10};
    p1.place_settelemnt(places, placesNum, board);

    places = {"Agricultural Land", "Hills"};
    placesNum = {12, 6};
    p1.place_road(places, placesNum, board);
    cout << "\n" << endl;

    // Player 2 places settlements and roads
    places = {"Mountains", "Pasture Land", "Sea"};
    placesNum = {8, 5, 0};
    p2.place_settelemnt(places, placesNum, board);

    try
    {
        // Player 3 tries to place a settlement in the same location as Player 2
        p3.place_settelemnt(places, placesNum, board);
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }

    places = {"Mountains", "Pasture Land"};
    placesNum = {8, 5};
    p2.place_road(places, placesNum, board);

    places = {"Forest", "Pasture Land", "Hills"};
    placesNum = {9, 4, 10};
    p2.place_settelemnt(places, placesNum, board);

    places = {"Forest", "Pasture Land"};
    placesNum = {9, 4};
    p2.place_road(places, placesNum, board);

    cout << "\n" << endl;

    // Player 3 places settlements and roads
    places = {"Mountains", "Pasture Land", "Sea"};
    placesNum = {10, 2, 0};
    p3.place_settelemnt(places, placesNum, board);

    places = {"Mountains", "Pasture Land"};
    placesNum = {10, 2};
    p3.place_road(places, placesNum, board);

    places = {"Agricultural Land", "Pasture Land", "Pasture Land"};
    placesNum = {4, 5, 11};
    p3.place_settelemnt(places, placesNum, board);

    places = {"Agricultural Land", "Pasture Land"};
    placesNum = {4, 5};
    p3.place_road(places, placesNum, board);

    cout << "\n" << endl;

    // Simulate dice rolls and turns for each player
    catan.roll_dice(p1);
    p1.place_road({"Forest", "Hills"}, {3, 10}, board);
    catan.end_turn(p1);

    catan.roll_dice(p2);
    catan.end_turn(p2);

    catan.roll_dice(p3);
    catan.end_turn(p3);

    try
    {
        // Player 2 tries to roll the dice again, but it's not their turn
        catan.roll_dice(p2);
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }

    // Player 1's turn
    catan.roll_dice(p1);
    catan.trade(p1, p2, "wood", "brick", 1, 1); // Player 1 trades 1 wood for 1 brick with Player 2
    catan.end_turn(p1);

    // Player 2's turn
    catan.roll_dice(p2);
    catan.trade(p2, p1, "wheat", "brick", 1, 1); // Player 2 trades 1 wheat for 1 brick with Player 1
    try
    {
        // Player 2 tries to buy a development card (they might not have enough resources)
        p2.buy_development_card();
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }

    // Simulate using development cards for Player 2
    vector<string> places1 = {"Pasture Land", "Hills"};
    vector<int> placesNum1 = {4, 10};
    vector<string> places2 = {"Mountains", "Sea"};
    vector<int> placesNum2 = {8, 0};

    // Player 2 bought one development card, we'll try to play all possible cards
    catan.player_development_card(p2, places1, placesNum1, places2, placesNum2, board); // Play the RoadBuildingCard
    catan.player_development_card(p2, "wool"); // Play the MonopolyCard
    catan.player_development_card(p2, "wood", "ore"); // Play the YearOfPlentyCard
    catan.player_development_card(p2); // Play the KnightCard

    // Player 3 tries to place a city
    places = {"Agricultural Land", "Pasture Land", "Pasture Land"};
    placesNum = {4, 5, 11};
    try
    {
        p3.place_city(places, placesNum, board);
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }
    catan.end_turn(p3);

    // Print points for each player
    p1.print_points();
    p2.print_points();
    p3.print_points();

    // Announce the winner
    catan.print_winner();

    return 0;
}
