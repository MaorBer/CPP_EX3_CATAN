// maorw9@gmail.com
// 212305965

#include "../hpp_files/player.hpp"
#include "../hpp_files/developmentCard.hpp"
#include "../hpp_files/knightCard.hpp"
#include "../hpp_files/VictoryPointCard.hpp"
#include "../hpp_files/MonopolyCard.hpp"
#include "../hpp_files/RoadBuildingCard.hpp"
#include "../hpp_files/YearOfPlentyCard.hpp"

using namespace std;

namespace ariel
{

    Player::Player(string _name)
    {
        this->_name = _name;
        this->_wood = 0;
        this->_bricks = 0;
        this->_wheat = 0;
        this->_ore = 0;
        this->_wool = 0;
    }

    string Player::get_name() const
    {
        return _name;
    }

    void Player::set_name(const string &_name)
    {
        this->_name = _name;
    }

    std::vector<std::unique_ptr<DevelopmentCard>> &Player::get_development_cards()
    {
        return development_cards;
    }

    const set<Settlement> &Player::get_settlements() const
    {
        return my_settlements;
    }

    const set<Road> &Player::get_roads() const
    {
        return my_roads;
    }

    const set<City> &Player::get_cities() const
    {
        return my_cities;
    }

    int Player::get_wood() const
    {
        return _wood;
    }

    void Player::set_wood(int amount)
    {
        _wood = amount;
    }

    int Player::get_bricks() const
    {
        return _bricks;
    }

    void Player::set_bricks(int _amount)
    {
        _bricks = _amount;
    }

    int Player::get_wheat() const
    {
        return _wheat;
    }

    void Player::set_wheat(int _amount)
    {
        _wheat = _amount;
    }

    int Player::get_ore() const
    {
        return _ore;
    }

    void Player::set_ore(int _amount)
    {
        _ore = _amount;
    }

    int Player::get_wool() const
    {
        return _wool;
    }

    void Player::set_wool(int _amount)
    {
        _wool = _amount;
    }

    bool Player::is_possible_road(Road my_road)
    {
        for (const auto &possible_road : this->possible_roads)
        {
            if (my_road == possible_road)
            {
                return true;
            }
        }
        return false;
    }

    bool Player::is_possible_settlement(Settlement my_settlement)
    {
        for (const auto &possible_settlement : this->possible_settlements)
        {
            if (my_settlement == possible_settlement)
            {
                return true;
            }
        }
        return false;
    }

    void Player::get_cards(string _resource, int _amount)
    {
        if (_resource == "Mountains" || _resource == "ore")
        {
            this->_ore += _amount;
            if (_amount > 0)
            {
                cout << this->_name << " earned " << _amount << " ore" << endl;
            }
            else if (_amount < 0)
            {
                cout << this->_name << " lost " << _amount << " ore" << endl;
            }
        }
        else if (_resource == "Forest" || _resource == "wood")
        {
            this->_wood += _amount;
            if (_amount > 0)
            {
                cout << this->_name << " earned " << _amount << " wood" << endl;
            }
            else if (_amount < 0)
            {
                cout << this->_name << " lost " << _amount << " wood" << endl;
            }
        }
        else if (_resource == "Agricultural Land" || _resource == "wheat")
        {
            this->_wheat += _amount;
            if (_amount > 0)
            {
                cout << this->_name << " earned " << _amount << " wheat" << endl;
            }
            else if (_amount < 0)
            {
                cout << this->_name << " lost " << _amount << " wheat" << endl;
            }
        }
        else if (_resource == "Pasture Land" || _resource == "wool")
        {
            this->_wool += _amount;
            if (_amount > 0)
            {
                cout << this->_name << " earned " << _amount << " wool" << endl;
            }
            else if (_amount < 0)
            {
                cout << this->_name << " lost " << _amount << " wool" << endl;
            }
        }
        else if (_resource == "Hills" || _resource == "brick")
        {
            this->_bricks += _amount;
            if (_amount > 0)
            {
                cout << this->_name << " earned " << _amount << " brick" << endl;
            }
            else if (_amount < 0)
            {
                cout << this->_name << " lost " << _amount << " bricks" << endl;
            }
        }
    }

    bool Player::resource_exist(string _resource, int _num)
    {
        if (_resource == "Mountains" || _resource == "ore")
        {
            if (this->_ore - _num < 0)
                return false;
        }
        else if (_resource == "Forest" || _resource == "wood")
        {
            if (this->_wood - _num < 0)
                return false;
        }
        else if (_resource == "Agricultural Land" || _resource == "wheat")
        {
            if (this->_wheat - _num < 0)
                return false;
        }
        else if (_resource == "Pasture Land" || _resource == "wool")
        {
            if (this->_wool - _num < 0)
                return false;
        }
        else if (_resource == "Hills" || _resource == "brick")
        {
            if (this->_bricks - _num < 0)
                return false;
        }
        return true;
    }

    void Player::place_settelemnt(vector<string> _places, vector<int> places_num, Board &_board)
    {
        if (_places.size() != 3 || places_num.size() != 3)
        {
            throw std::invalid_argument("invalid number of places or placesNum provided");
        }
        if ((this->_bricks < 1 || this->_wood < 1 || this->_wheat < 1 || this->_wool < 1) && _board.get_settlements().size() > 6)
        {
            throw std::runtime_error("placing Settlement: Insufficient resources");
        }

        Tile tile1(_places[0], places_num[0]);
        Tile tile2(_places[1], places_num[1]);
        Tile tile3(_places[2], places_num[2]);

        Settlement settlement(this->_name, tile1, tile2, tile3);
        City city(this->_name, tile1, tile2, tile3);
        if (_board.is_possible_settlement(settlement, city))
        {
            _board.get_settlements().insert(settlement);
            if (_board.get_settlements().size() <= 6)
            {
                this->get_cards(tile1.get_terrain(), 1);
                this->get_cards(tile2.get_terrain(), 1);
                this->get_cards(tile3.get_terrain(), 1);
            }
            else
            {
                this->_bricks--;
                this->_wood--;
                this->_wheat--;
                this->_wool--;
            }

            Road road1(this->_name, tile1, tile2);
            Road road2(this->_name, tile1, tile3);
            Road road3(this->_name, tile2, tile3);

            this->possible_roads.insert(road1);
            this->possible_roads.insert(road2);
            this->possible_roads.insert(road3);
        }
        else
        {
            throw std::runtime_error("cant place settlement here");
        }
        this->my_settlements.insert(settlement);
        cout << this->_name << " placed the Settlement successfully" << endl;
    }

    void Player::place_road(vector<string> _places, vector<int> places_num, Board &_board)
    {
        if (_places.size() != 2 || places_num.size() != 2)
        {
            throw std::invalid_argument("invalid number of places or placesNum provided");
        }

        if ((this->_bricks < 1 || this->_wood < 1) && _board.get_settlements().size() > 6)
        {
            throw std::runtime_error("placing Road: Insufficient resources");
            return;
        }

        Tile tile1(_places[0], places_num[0]);
        Tile tile2(_places[1], places_num[1]);
        Road road(this->_name, tile1, tile2);
        if ((is_possible_road(road) || _board.get_settlements().size() < 6) && _board.is_possible_road(road))
        {
            this->possible_roads.erase(road);
            _board.get_roads().insert(road);
            if (_board.get_roads().size() > 6)
            {
                this->_bricks--;
                this->_wood--;
            }
            for (auto &neighbor : tile1.get_near_by_areas())
            {
                if (tile2.get_near_by_areas().find(neighbor) != tile2.get_near_by_areas().end())
                {
                    Road road1(this->_name, tile1, *neighbor);
                    Road road2(this->_name, tile2, *neighbor);
                    this->possible_roads.insert(road1);
                    this->possible_roads.insert(road2);
                }
            }
        }
        else
        {
            throw std::runtime_error("cant place road here");
        }
        this->my_roads.insert(road);
        cout << this->_name << " placed the Road successfully" << endl;
    }

    void Player::place_city(vector<string> _places, vector<int> places_num, Board &_board)
    {
        if (_places.size() != 3 || places_num.size() != 3)
        {
            throw std::invalid_argument("invalid number of places or placesNum provided");
        }
        if (this->_ore < 3 || this->_wheat < 2)
        {
            throw std::runtime_error("placing City: Insufficient resources");
            return;
        }
        Tile tile1(_places[0], places_num[0]);
        Tile tile2(_places[1], places_num[1]);
        Tile tile3(_places[2], places_num[2]);
        Settlement settlement(this->_name, tile1, tile2, tile3);
        City city(this->_name, tile1, tile2, tile3);
        if (this->my_settlements.find(settlement) != this->my_settlements.end())
        {
            _board.get_settlements().erase(settlement);
            _board.get_cities().insert(city);
        }
        else
        {
            throw std::runtime_error("cant place city here");
        }
        this->_bricks--;
        this->_wood--;
        this->_wheat--;
        this->_wool--;
        this->my_cities.insert(city);
        cout << this->_name << " placed the City successfully" << endl;
    }

    void Player::distribute_resources(int _num)
    {

        for (const auto &settlement : this->my_settlements)
        {
            for (const auto &tile : settlement.get_near_by_areas())
            {
                if (tile.get_number() == _num && tile != *(KnightCard::get_knight()))
                {
                    this->get_cards(tile.get_terrain(), 1);
                }
            }
        }

        for (const auto &city : this->my_cities)
        {
            for (const auto &tile : city.get_near_by_areas())
            {
                if (tile.get_number() == _num && tile != *(KnightCard::get_knight()))
                {
                    this->get_cards(tile.get_terrain(), 1);
                }
            }
        }
    }

    void Player::show_cards() const
    {
        std::cout << "Cards of " << this->get_name() << ": " << "wood" << ": " << _wood << ", " << "wool" << ": " << _wool << ", " << "bricks" << ": " << _bricks << ", " << "ore" << ": " << _ore << ", " << "wheat" << ": " << _wheat << ", " << std::endl;
    }

    void Player::discard_cards()
    {
        int total_cards = this->_bricks + this->_ore + this->_wheat + this->_wood + this->_wool;
        if (total_cards > 7)
        {
            std::cout << this->get_name() << " has " << total_cards << " cards and needs to discard " << total_cards / 2 << " cards." << std::endl;
            int cards_to_discard = total_cards / 2;
            while (cards_to_discard > 0)
            {
                std::string _resource;
                int _amount;
                show_cards();
                cout << cards_to_discard << " cards needs to be discard" << endl;
                std::cout << "Enter the resource to discard and the amount (e.g., wood 2): ";
                std::cin >> _resource >> _amount;

                if (_amount <= cards_to_discard)
                {
                    if (resource_exist(_resource, _amount))
                    {
                        get_cards(_resource, -_amount);
                        cards_to_discard -= _amount;
                    }
                    else
                    {
                        std::cout << "You do not have enough " << _resource << " to discard. Try again." << std::endl;
                    }
                }
                else
                {
                    std::cout << "too much cards to discard. Try again." << std::endl;
                }
            }

            std::cout << "Discard completed." << std::endl;
        }
    }

    void Player::take_all_resources(Player &_other, string _resource)
    {
        int _count = 0;
        while (_other.resource_exist(_resource, 1))
        {
            _other.get_cards(_resource, -1);
            this->get_cards(_resource, 1);
            _count++;
        }
        cout << this->_name << " took " << _count << " " << _resource << " from " << _other._name << endl;
    }

    void Player::buy_development_card()
    {
        if (this->_ore < 1 || this->_wheat < 1 || this->_wool < 1)
        {
            throw std::runtime_error("buying Development card: Insufficient resources");
            return;
        }
        this->_ore--;
        this->_wheat--;
        this->_wool--;
        random_device _rd;
        mt19937 _gen(_rd());
        uniform_int_distribution<> distr(0, 9);
        std::unique_ptr<DevelopmentCard> new_card;
        int card_type = distr(_gen);
        string _type;
        if (card_type < 3)
        {
            uniform_int_distribution<> progress_distr(0, 2);
            int progress_type = progress_distr(_gen);

            if (progress_type == 0)
            {
                new_card = std::make_unique<MonopolyCard>();
                _type = "Monopoly Card";
            }
            else if (progress_type == 1)
            {
                new_card = std::make_unique<RoadBuildingCard>();
                _type = "Road Building Card";
            }
            else
            {
                new_card = std::make_unique<YearOfPlentyCard>();
                _type = "Year of Plenty Card";
            }
        }
        else if (card_type < 6)
        {
            new_card = std::make_unique<KnightCard>();
            _type = "Knight Card";
        }
        else
        {
            new_card = std::make_unique<VictoryPointCard>();
            _type = "Victory Point Card";
        }

        development_cards.push_back(std::move(new_card));
        std::cout << "Development card bought successfully: " << _type << std::endl;
    }

    int Player::my_points()
    {
        int points_from_buildings = this->my_settlements.size() + this->my_cities.size() * 2;
        int points_from_victory_cards = std::count_if(development_cards.begin(), development_cards.end(), [](const std::unique_ptr<DevelopmentCard> &card)
                                                      { return dynamic_cast<VictoryPointCard *>(card.get()) != nullptr; });
        int points_from_knight_cards = std::count_if(development_cards.begin(), development_cards.end(), [](const std::unique_ptr<DevelopmentCard> &card)
                                                     { return dynamic_cast<KnightCard *>(card.get()) != nullptr; });
        if (points_from_knight_cards == 3)
            points_from_knight_cards = 2;
        return points_from_buildings + points_from_victory_cards + points_from_knight_cards;
    }

    void Player::print_points()
    {
        cout << this->get_name() << " has " << this->my_points() << " points" << endl;
    }

    bool Player::operator==(const Player &player) const
    {
        return this->get_name() == player.get_name();
    }

    void Player::print_all_info()
    {
        cout << "Player Name: " << _name << endl;
        cout << "Resources:" << endl;
        cout << "  Wood: " << _wood << endl;
        cout << "  Bricks: " << _bricks << endl;
        cout << "  Wheat: " << _wheat << endl;
        cout << "  Ore: " << _ore << endl;
        cout << "  Wool: " << _wool << endl;
        cout << "Settlements:" << endl;
        for (const auto &settlement : my_settlements)
        {
            cout << "  " << settlement << endl;
        }

        cout << "Roads:" << endl;
        for (const auto &road : my_roads)
        {
            cout << "  " << road << endl;
        }

        cout << "Cities:" << endl;
        for (const auto &city : my_cities)
        {
            cout << "  " << city << endl;
        }

        cout << "Development Cards:" << endl;
        for (const auto &card : development_cards)
        {
            if (dynamic_cast<MonopolyCard *>(card.get()))
            {
                cout << "  Monopoly Card" << endl;
            }
            else if (dynamic_cast<KnightCard *>(card.get()))
            {
                cout << "  Knight Card" << endl;
            }
            else if (dynamic_cast<RoadBuildingCard *>(card.get()))
            {
                cout << "  Road Building Card" << endl;
            }
            else if (dynamic_cast<YearOfPlentyCard *>(card.get()))
            {
                cout << "  Year of Plenty Card" << endl;
            }
            else if (dynamic_cast<VictoryPointCard *>(card.get()))
            {
                cout << "  Victory Point Card" << endl;
            }
        }

        print_points();
    }
}