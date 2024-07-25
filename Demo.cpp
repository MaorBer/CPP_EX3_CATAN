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
    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");

    Catan catan(p1, p2, p3);

    Board& board = catan.get_board();

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

    places = {"Mountains", "Pasture Land", "Sea"};
    placesNum = {8, 5, 0};
    p2.place_settelemnt(places, placesNum, board);

    try
    {
        p3.place_settelemnt(places, placesNum, board); // p3 tries to place a settlement in the same location as p2.
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

    catan.roll_dice(p1);                                    // Simulating dice roll for player 1
    p1.place_road({"Forest", "Hills"}, {3, 10}, board); // Placing a road for player 1
    catan.end_turn(p1);                                     // Ending turn for player 1

    catan.roll_dice(p2); // Simulating dice roll for player 2
    catan.end_turn(p2);  // Ending turn for player 2

    catan.roll_dice(p3); // Simulating dice roll for player 3
    catan.end_turn(p3);  // Ending turn for player 3

    try{
        catan.roll_dice(p2); // p2 tries to roll the dice again, but it's not his turn.
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }

    catan.roll_dice(p1);
    catan.trade(p1, p2, "wood", "brick", 1, 1); // p1 trades 1 wood for 1 brick with p2.
    catan.end_turn(p1);                        // p1 ends his turn.

    catan.roll_dice(p2);
    catan.trade(p2, p1, "wheat", "brick", 1, 1); // p1 trades 1 wood for 1 brick with p2.
    try
    {
        p2.buy_development_card(); // p2 tries to buy a development card(he might not have enough resources)
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }

    vector<string> places1 = {"Pasture Land", "Hills"};
    vector<int> placesNum1 = {4, 10};
    vector<string> places2 = {"Mountains", "Sea"};
    vector<int> placesNum2 = {8, 0};

    //player2 bought one DevelopmentCard, we dont know which he got so we  will try to play them all.
    catan.player_development_card(p2, places1, placesNum1, places2, placesNum2, board); // play the RoadBuildingCard. the turn ends right after
    catan.player_development_card(p2, "wool"); // play the MonopolCard. the turn ends right after
    catan.player_development_card(p2, "wood", "ore"); // play the YearOfPlentyCard. the turn ends right after
    catan.player_development_card(p2); // play the KnightCard. the turn ends right after

    places = {"Agricultural Land", "Pasture Land", "Pasture Land"};
    placesNum = {4, 5, 11};
    try
    {
        p3.place_city(places, placesNum, board); // p2 tries to place a city(he might not have enough resources)
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }
    catan.end_turn(p3);

    p1.print_points();
    p2.print_points();
    p3.print_points();

    catan.print_winner();

    return 0;
}
