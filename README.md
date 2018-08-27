# predator-prey-simulation
A simple simulation for a predator-prey relationship implemented in C++. Completed the fall of 2017.

This is a predator-prey simulation using ants and doodlebugs. The point of this assignment is to create a base class called Critter and then derive the ant and doodlebug classes from critter. The program will take in a seed each time it is run and print out every step of the simulation as well as a count of all of the doodlebugs and ants and stastics thereof.

# Simulation Requirements
- The critters live in a 20x20 grid of cells where only one critter may occupy a sell at a time and critters may not move beyond the edges.
- Time is simulated in steps and every critter must perform some action every time step.
- Ants may *move* or *breed*. The ants will attempt to move up, down, left, or right every step. If the cell is occupied or the ant would move off the grid, the ant stays. Every three steps the ant will breed at the end of the time step. Breeding creates a new ant in an adjacent, empty cell. If there is no empty cell, it cannot breed.
- Doodlebugs will *move*, *breed*, or *starve*. They will move to a cell containing an ant to eat it, or otherwise move following the same rules as the ant if they cannot eat. If the doodlebug survives eight steps it will spawn a new doodlebug, following ant rules. If the doodlebug has not eaten an ant within three steps, it will starve and die and be removed from the grid of cells.
- All doodlebugs will move before ants.
- Ants are represented as "O", doodlebugs as "X"

Please initialize the board with 5 doodlebugs and 100 ants. Create a base class Critter and set things up so that an object of type Critter cannot be declared outside of the derived classes. The move() function must be virtual and the C++11 override may be used as appropriate. For every time step you must print a grid to represent the change of each pahse (a grid for the doodlebug movement, for the ant movement, breeding/starvation). Each phase grid should have a label to identify what has changed and a summary of events should be printed at the final phase.

# Notes
A makefile is included for running compiling and running the program. Simply use `make all` will compile the program. The program was developed in Visual Code on Windows 10 and tested in Cygwin using the g++ compiler, further tested in a Debian lab environment with g++.
