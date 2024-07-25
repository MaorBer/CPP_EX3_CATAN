// maorw9@gmail.com
// 212305965

#include "../hpp_files/catan.hpp"

namespace ariel
{

    Catan::Catan(Player &p1, Player &p2, Player &p3) : _p1(p1), _p2(p2), _p3(p3), curr_player(&_p1), _board()
    {
        std::srand(std::time(nullptr));
        std::cout << "Catan game initialized with players: " << _p1.get_name() << ", " << _p2.get_name() << ", " << _p3.get_name() << std::endl;
        std::cout << "Starting player is " << (*curr_player).get_name() << "\n"
                  << std::endl;
    }

    Board &Catan::get_board()
    {
        return _board;
    }

    void Catan::roll_dice(Player &_player)
    {
        if (*curr_player == _player)
        {
            int die1 = rand() % 6 + 1;
            int die2 = rand() % 6 + 1;
            int sum = die1 + die2;
            cout << _player.get_name() << " rolled the dices and got " << sum << endl;
            if (sum == 7)
            {
                _p1.discard_cards();
                _p2.discard_cards();
                _p3.discard_cards();
                string _terrain;
                int _num;
                std::cout << "Enter a resource and a number of a tile you want to put the knight on (e.g., Agricultural Land 4 ): ";
                std::cin >> _terrain >> _num;
                KnightCard::set_knight(_terrain, _num);
            }
            else
            {
                _p1.distribute_resources(sum);
                _p2.distribute_resources(sum);
                _p3.distribute_resources(sum);
            }
        }
        else
        {
            throw std::runtime_error("its not " + _player.get_name() + "'s turn, its now " + (*curr_player).get_name() + "'s turn");
        }
    }

    void Catan::end_turn(Player &_player)
    {
        if (curr_player == &_player)
        {
            std::cout << _player.get_name() << "'s turn has ended." << std::endl;
            if (_player.my_points() >= 10)
            {
                print_winner();
                std::exit(0);
            }
            if (curr_player == &_p1)
            {
                curr_player = &_p2;
            }
            else if (curr_player == &_p2)
            {
                curr_player = &_p3;
            }
            else
            {
                curr_player = &_p1;
            }
            std::cout << "It's now " << curr_player->get_name() << "'s turn.\n"
                      << std::endl;
        }
        else
        {
            std::cout << "It's not your turn to end, it's now " << curr_player->get_name() << "'s turn\n"
                      << std::endl;
        }
    }

    void Catan::trade(Player &_p1, Player &_p2, string _resource1, string _resource2, int _num1, int _num2)
    {
        if ((*this->curr_player) == _p1)
        {
            if (_p1.resource_exist(_resource1, _num1))
            {
                if (_p2.resource_exist(_resource2, _num2))
                {
                    _p1.get_cards(_resource1, _num1 * (-1));
                    _p1.get_cards(_resource2, _num2);
                    _p2.get_cards(_resource2, _num2 * (-1));
                    _p2.get_cards(_resource1, _num1);
                    std::cout << _p1.get_name() << " and " << _p2.get_name() << " traded. "
                              << _p1.get_name() << " gave " << _num1 << " " << _resource1
                              << " and received " << _num2 << " " << _resource2 << "." << std::endl;
                }
                else
                {
                    cout << _p2.get_name() + " lacks resources" << endl;
                }
            }
            else
            {
                cout << _p1.get_name() + " lacks resources" << endl;
            }
        }
        else
        {
            cout << "its not " + _p1.get_name() + "'s turn, its now " + (*curr_player).get_name() + "'s turn" << endl;
        }
    }

    void Catan::player_development_card(Player &_player, string _resource)
    {
        if ((*this->curr_player) == _player)
        {
            auto it = std::find_if(_player.get_development_cards().begin(), _player.get_development_cards().end(), [](const std::unique_ptr<DevelopmentCard> &card)
                                   { return dynamic_cast<MonopolyCard *>(card.get()) != nullptr; });

            if (it != _player.get_development_cards().end())
            {
                MonopolyCard *monopoly_card = dynamic_cast<MonopolyCard *>(it->get());
                if (monopoly_card)
                {
                    std::vector<std::reference_wrapper<ariel::Player>> players = {_p1, _p2, _p3};
                    monopoly_card->play(_player, players, _resource);
                    _player.get_development_cards().erase(it); // Remove the card from the vector
                    std::cout << "Monopoly card played successfully." << std::endl;
                    this->end_turn(_player);
                }
            }
            else
            {
                std::cout << "You do not have a Monopoly card." << std::endl;
            }
        }
        else
        {
            cout << "its not " + _player.get_name() + "'s turn, its now " + (*curr_player).get_name() + "'s turn" << endl;
        }
    }

    void Catan::player_development_card(Player &_player, std::vector<std::string> _places1, std::vector<int> places_num1, std::vector<std::string> _places2, std::vector<int> places_num2, Board &_board)
    {
        if (*this->curr_player == _player)
        {
            auto it = std::find_if(_player.get_development_cards().begin(), _player.get_development_cards().end(), [](const std::unique_ptr<DevelopmentCard> &card)
                                   { return dynamic_cast<RoadBuildingCard *>(card.get()) != nullptr; });

            if (it != _player.get_development_cards().end())
            {
                RoadBuildingCard *road_building_card = dynamic_cast<RoadBuildingCard *>(it->get());
                if (road_building_card)
                {
                    road_building_card->play(_player, _places1, places_num1, _places2, places_num2, _board);
                    _player.get_development_cards().erase(it);
                    std::cout << "Road Building card played successfully." << std::endl;
                    this->end_turn(_player);
                }
            }
            else
            {
                std::cout << "You do not have a Road Building card." << std::endl;
            }
        }
        else
        {
            std::cout << "It's not " + _player.get_name() + "'s turn, it's now " + this->curr_player->get_name() + "'s turn" << std::endl;
        }
    }

    void Catan::player_development_card(Player &_player, const std::string &_resource1, const std::string &_resource2)
    {
        if (*this->curr_player == _player)
        {
            auto it = std::find_if(_player.get_development_cards().begin(), _player.get_development_cards().end(), [](const std::unique_ptr<DevelopmentCard> &card)
                                   { return dynamic_cast<YearOfPlentyCard *>(card.get()) != nullptr; });

            if (it != _player.get_development_cards().end())
            {
                YearOfPlentyCard *year_of_plenty_card = dynamic_cast<YearOfPlentyCard *>(it->get());
                if (year_of_plenty_card)
                {
                    year_of_plenty_card->play(_player, _resource1, _resource2);
                    _player.get_development_cards().erase(it);
                    std::cout << "Year of Plenty card played successfully." << std::endl;
                    this->end_turn(_player);
                }
            }
            else
            {
                std::cout << "You do not have a Year of Plenty card." << std::endl;
            }
        }
        else
        {
            std::cout << "It's not " + _player.get_name() + "'s turn, it's now " + this->curr_player->get_name() + "'s turn" << std::endl;
        }
    }

    void Catan::player_development_card(Player &_player)
    {
        if (*this->curr_player == _player)
        {
            auto it = std::find_if(_player.get_development_cards().begin(), _player.get_development_cards().end(), [](const std::unique_ptr<DevelopmentCard> &card)
                                   { return dynamic_cast<KnightCard *>(card.get()) != nullptr; });

            if (it != _player.get_development_cards().end())
            {
                KnightCard *knight_card = dynamic_cast<KnightCard *>(it->get());
                if (knight_card)
                {
                    knight_card->play(_player);
                    _player.get_development_cards().erase(it);
                    std::cout << "Knight card played successfully." << std::endl;
                    this->end_turn(_player);
                }
            }
            else
            {
                std::cout << "You do not have a Knight card." << std::endl;
            }
        }
        else
        {
            std::cout << "It's not " + _player.get_name() + "'s turn, it's now " + this->curr_player->get_name() + "'s turn" << std::endl;
        }
        this->end_turn(_player);
    }

    void Catan::print_winner()
    {
        int p1_points = _p1.my_points();
        int p2_points = _p2.my_points();
        int p3_points = _p3.my_points();
        if (p1_points < 10 && p2_points < 10 && p3_points < 10)
        {
            std::cout << "There is no winner, No one has reached 10 points\n";
            return;
        }

        if (p1_points > p2_points && p1_points > p3_points)
        {
            std::cout << "The winner is Player 1: " << _p1.get_name() << " with " << p1_points << " points!\n";
        }
        else if (p2_points > p1_points && p2_points > p3_points)
        {
            std::cout << "The winner is Player 2: " << _p2.get_name() << " with " << p2_points << " points!\n";
        }
        else if (p3_points > p1_points && p3_points > p2_points)
        {
            std::cout << "The winner is Player 3: " << _p3.get_name() << " with " << p3_points << " points!\n";
        }
        else
        {
            std::cout << "There is a tie!\n";
            if (p1_points == p2_points && p1_points > p3_points)
            {
                std::cout << "Players 1 and 2 (" << _p1.get_name() << " and " << _p2.get_name() << ") tie with " << p1_points << " points!\n";
            }
            else if (p1_points == p3_points && p1_points > p2_points)
            {
                std::cout << "Players 1 and 3 (" << _p1.get_name() << " and " << _p3.get_name() << ") tie with " << p1_points << " points!\n";
            }
            else if (p2_points == p3_points && p2_points > p1_points)
            {
                std::cout << "Players 2 and 3 (" << _p2.get_name() << " and " << _p3.get_name() << ") tie with " << p2_points << " points!\n";
            }
            else
            {
                std::cout << "All players tie with " << p1_points << " points!\n";
            }
        }
    }
}