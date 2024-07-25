// maorw9@gmail.com
// 212305965

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <memory>
#include <string>
#include <algorithm>
#include "board.hpp"
#include "tile.hpp"
#include "settlement.hpp"
#include "city.hpp"
#include "road.hpp"

using namespace std;

namespace ariel
{
    class DevelopmentCard;
    class MonopolyCard;
    class KnightCard;
    class RoadBuildingCard;
    class YearOfPlentyCard;

    class Player
    {
    private:
        std::vector<std::unique_ptr<DevelopmentCard>> development_cards;
        string _name;
        set<Settlement> possible_settlements;
        set<Road> possible_roads;
        set<Settlement> my_settlements;
        set<Road> my_roads;
        set<City> my_cities;
        int _wood;
        int _bricks;
        int _wheat;
        int _ore;
        int _wool;
        bool is_possible_road(Road my_road);
        bool is_possible_settlement(Settlement my_settelemnt);
        void show_cards() const;

    public:
        Player(string _name);
        string get_name() const;
        void set_name(const string &_name);
        std::vector<std::unique_ptr<DevelopmentCard>> &get_development_cards();
        const set<Settlement> &get_settlements() const;
        const set<Road> &get_roads() const;
        const set<City> &get_cities() const;
        int get_wood() const;
        void set_wood(int _amount);
        int get_bricks() const;
        void set_bricks(int _amount);
        int get_wheat() const;
        void set_wheat(int _amount);
        int get_ore() const;
        void set_ore(int _amount);
        int get_wool() const;
        void set_wool(int _amount);
        void place_settelemnt(vector<string> _places, vector<int> places_num, Board &_board);
        void place_road(vector<string> _places, vector<int> places_num, Board &_board);
        void place_city(vector<string> _places, vector<int> places_num, Board &_board);
        void get_cards(string _resource, int _amount);
        bool resource_exist(string _resource, int _num);
        void discard_cards();
        void distribute_resources(int _num);
        void take_all_resources(Player &_other, string _resource);
        void buy_development_card();
        int my_points();
        void print_points();
        void print_all_info();
        bool operator==(const Player &_player) const;
    };
}

#endif // PLAYER_H