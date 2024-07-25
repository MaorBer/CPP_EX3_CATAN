// maorw9@gmail.com
// 212305965

#include "../hpp_files/MonopolyCard.hpp"

namespace ariel {

void MonopolyCard::play(Player& _player, std::vector<std::reference_wrapper<ariel::Player>> _players, const std::string& _resource) {
    for (auto& other_player_ref : _players) {
        Player& other_player = other_player_ref.get();
        if (&other_player != &_player) {
            _player.take_all_resources(other_player, _resource);
        }
    }
    std::cout << "Monopoly card played by " << _player.get_name() << ": All " << _resource << " taken from other players." << std::endl;
}

}
