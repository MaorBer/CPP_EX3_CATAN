// maorw9@gmail.com
// 212305965

#ifndef MONOPOLYCARD_HPP
#define MONOPOLYCARD_HPP

#include <vector>
#include <string>
#include "developmentCard.hpp"
#include "player.hpp"

namespace ariel {

class Player;

class MonopolyCard : public DevelopmentCard {
public:
    void play(Player& _player, std::vector<std::reference_wrapper<ariel::Player>> _players, const std::string& _resource);
};

}

#endif // MONOPOLYCARD_HPP