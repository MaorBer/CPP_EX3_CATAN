// maorw9@gmail.com
// 212305965

#include "../hpp_files/YearOfPlentyCard.hpp"

namespace ariel
{

    void YearOfPlentyCard::play(Player &_player, std::string _resource1, std::string _resource2)
    {
        _player.get_cards(_resource1, 1);
        _player.get_cards(_resource2, 1);
        std::cout << "Year of Plenty card played by " << _player.get_name() << ": You received " << _resource1 << " and " << _resource2 << " from the bank." << std::endl;
    }

}
