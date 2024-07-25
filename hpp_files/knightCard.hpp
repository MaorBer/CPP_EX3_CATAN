// maorw9@gmail.com
// 212305965

#ifndef KNIGHTCARD_HPP
#define KNIGHTCARD_HPP

#include "developmentCard.hpp"
#include "tile.hpp"
#include "player.hpp"
#include <string>

namespace ariel
{

    class KnightCard : public DevelopmentCard
    {
    public:
        void play(Player &_player);
        static void set_knight(const std::string &_name, int _number);
        static Tile *get_knight();

    private:
        static Tile *_knight;
    };

}

#endif // KNIGHTCARD_HPP