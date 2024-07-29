// maorw9@gmail.com
// 212305965

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "hpp_files/player.hpp"
#include "hpp_files/catan.hpp"
#include "hpp_files/board.hpp"

using namespace ariel;

TEST_CASE("Player::placeSettelemnt, placeRoad, placeCity")
{
    Player p1("Maor");
    Player p2("Yossi");
    Player p3("Liya");
    Catan catan(p1, p2, p3);
    Board &_board = catan.get_board();
    
    p1.set_ore(5);
    p1.set_wheat(5);
    
    std::vector<std::string> _places = {"Forest", "Mountains", "Hills"};
    std::vector<int> places_num = {9, 5, 10};
    
    CHECK_NOTHROW(p1.place_settelemnt(_places, places_num, _board));
    CHECK_NOTHROW(p1.place_city(_places, places_num, _board));
    
    CHECK_THROWS_AS(p1.place_settelemnt(_places, places_num, _board), std::runtime_error);
    
    _places = {"Forest", "Mountains"};
    places_num = {9, 5};
    CHECK_NOTHROW(p1.place_road(_places, places_num, _board));
}

TEST_CASE("Catan::rollDice")
{
    Player p1("Maor"), p2("Yossi"), p3("Liya");
    Catan game(p1, p2, p3);
    
    CHECK_NOTHROW(game.roll_dice(p1));
    CHECK_NOTHROW(game.end_turn(p1));
    CHECK_THROWS_AS(game.roll_dice(p1), std::runtime_error);
}

TEST_CASE("Catan::endTurn")
{
    Player p1("Maor"), p2("Yossi"), p3("Liya");
    Catan game(p1, p2, p3);
    
    CHECK_NOTHROW(game.end_turn(p1));
}

TEST_CASE("Catan::trade")
{
    Player p1("Maor"), p2("Yossi"), p3("Liya");
    Catan game(p1, p2, p3);
    
    p1.set_wood(2);
    p2.set_bricks(2);
    CHECK_NOTHROW(game.trade(p1, p2, "wood", "brick", 1, 1));
}

TEST_CASE("Catan::playDevelopmentCard")
{
    Player p1("Maor"), p2("Yossi"), p3("Liya");
    Catan game(p1, p2, p3);
    Board &board = game.get_board();
    
    p2.set_ore(30);
    p2.set_wool(30);
    p2.set_wheat(30);
    
    CHECK_NOTHROW(p1.place_settelemnt({"Agricultural Land", "Forest", "Hills"}, {5, 8, 3}, board));
    
    for (int i = 0; i < 30; i++)
    {
        CHECK_NOTHROW(p2.buy_development_card());
    }
    
    CHECK_NOTHROW(game.player_development_card(p2, {"Hills", "Forest"}, {8, 3}, {"Pasture Land", "Hills"}, {5, 8}, board));
    CHECK_NOTHROW(game.player_development_card(p2, "wool"));
    CHECK_NOTHROW(game.player_development_card(p2, "wood", "ore"));
    CHECK_NOTHROW(game.player_development_card(p2));
}

TEST_CASE("Catan::printWinner")
{
    Player p1("Maor"), p2("Yossi"), p3("Liya");
    Catan game(p1, p2, p3);
    
    CHECK_NOTHROW(game.print_winner());
}

TEST_CASE("Board::setup")
{
    Board board;
    
    CHECK(board.get_tiles().size() == 19);
    CHECK(board.get_tiles()[0].get_terrain() == "Mountains");
    CHECK(board.get_tiles()[0].get_number() == 5);
    CHECK(board.get_roads().empty());
    CHECK(board.get_settlements().empty());
    CHECK(board.get_cities().empty());
}

TEST_CASE("End cases - Settlement on Settlement")
{
    Player p1("Maor"), p2("Yossi"), p3("Liya");
    Catan game(p1, p2, p3);
    Board &board = game.get_board();
    
    CHECK_NOTHROW(p1.place_settelemnt({"Agricultural Land", "Forest", "Hills"}, {5, 8, 3}, board));
    CHECK_THROWS(p2.place_settelemnt({"Agricultural Land", "Forest", "Hills"}, {5, 8, 3}, board));
}

TEST_CASE("End cases - City First")
{
    Player p1("Maor"), p2("Yossi"), p3("Liya");
    Catan game(p1, p2, p3);
    Board &board = game.get_board();
    
    CHECK_THROWS(p1.place_city({"Agricultural Land", "Forest", "Hills"}, {5, 8, 3}, board));
}

TEST_CASE("End cases - Settlement 1 road from Settlement")
{
    Player p1("Maor"), p2("Yossi"), p3("Liya");
    Catan game(p1, p2, p3);
    Board &board = game.get_board();
    
    CHECK_NOTHROW(p1.place_settelemnt({"Agricultural Land", "Forest", "Hills"}, {5, 8, 3}, board));
    CHECK_THROWS(p2.place_settelemnt({"Forest", "Agricultural Land", "Forest"}, {10, 5, 8}, board));
}
