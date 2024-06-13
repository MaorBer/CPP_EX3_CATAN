class Catan {
public:
    Catan(Player p1, Player p2, Player p3) : players{p1, p2, p3} {}

    void ChooseStartingPlayer() {
        int startIndex = rand() % 3;
        std::cout << "Starting player: " << players[startIndex].getName() << std::endl;
    }

    Board& getBoard() {
        return board;
    }

    void printWinner() const {
        for (const auto& player : players) {
            if (player.getPoints() >= 10) {
                std::cout << "Winner: " << player.getName() << std::endl;
                return;
            }
        }
        std::cout << "None" << std::endl;
    }

private:
    Board board;
    std::vector<Player> players;
};
