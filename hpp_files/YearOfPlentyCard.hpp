// maorw9@gmail.com
// 212305965

#ifndef YEAROFPLENTYCARD_HPP
#define YEAROFPLENTYCARD_HPP

#include <string>
#include "developmentCard.hpp"
#include "player.hpp"

namespace ariel
{

    class Player;

    class YearOfPlentyCard : public DevelopmentCard
    {
    public:
        void play(Player &_player, std::string _resource1, std::string _resource2);
    };

}

#endif // YEAROFPLENTYCARD_HPP
