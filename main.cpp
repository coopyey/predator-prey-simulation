//main.cpp
//Sets the simulation seed as well as runs the simulation.
//For grading purposes, the ability to step through turn by turn has been added.

#include <iostream>
#include <ctime>
#include "board.hpp"

int main() {
    Board theBoard(time(0)); //This ensures the seed is random each run

    char z;
    int ants = 1;
    int doods = 1;

    std::cout << "Hit enter to run each time step!\n";
    
    //Uncomment cin.get() to have ability to step through each time step one by one.
    //Some simulations run quite long so this may not be recommended.
    while (/*std::cin.get(z) &&*/ ((ants != 0) && (doods != 0))) {
        theBoard.stepForward(ants, doods);
    }

    std::cout << "\nSimulation done!\n";

    if (ants == 0) {
        std::cout << "Ant population died out.\nHit enter to end simulation.";
    } else if (doods == 0) {
        std::cout << "Doodlebug population died out.\nHit enter to end simulation.";
    }

    std::cin.get(z);

    return 0;
}