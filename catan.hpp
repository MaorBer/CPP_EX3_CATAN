#ifndef CATAN_HPP
#define CATAN_HPP



namespace ariel {
    class Catan {
    public:
        // Constructor
        Catan(Player p1, Player p2, Player p3);

        // Destructor
        // ~Catan();

        // Function declarations
        
        void ChooseStartingPlayer();
        Board getBoard();
        void printWinner();
    };


}
// Include any necessary headers here

// Declare your classes, functions, and variables here

#endif // CATAN_HPP