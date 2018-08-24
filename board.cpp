//board.cpp
//Implementation for the board.

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "board.hpp"
#include "ant.hpp"
#include "doodle.hpp"

//Public functions
//Constructor
Board::Board(unsigned int seed) {
    srand(seed);

    //this creates our empty board
    for (unsigned int i = 0; i < SIZE; i++) {
        for (unsigned int j = 0; j < SIZE; j++) {
            grid[i][j] = NULL;
        } //end for j
    } //end for i

    create(ANT, ANTS);
    create(DOODLE, DOODLES);
}

//Destructor
Board::~Board() {
    for (unsigned int i = 0; i < SIZE; i++) {
        for (unsigned int j = 0; j < SIZE; j++) {
            if (grid[i][j] != NULL) {
                delete grid[i][j];
            } //end if
        } //end for j
    }//end for i
}

void Board::set(int x, int y, Critter* crit) {
    if ((x >= 0) && (x < SIZE) && (y >= 0) && (y < SIZE)) {
        grid[x][y] = crit;
    }
}

void Board::display() const {
    std::cout << std::endl << std::endl;

    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++) {
            if (grid[i][j] == NULL) {
                std::cout << "-";
            } else {
                std::cout << grid[i][j]->symbol();
            } //end if/else
        }//end for i
        std::cout << std::endl;
    }//end for j
}

void Board::count(int& ants, int& doods) const {
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++) {
            if (grid[i][j] != NULL) {
                if (grid[i][j]->type() == ANT) {
                    ants++;
                } else if (grid[i][j]->type() == DOODLE) {
                    doods++;
                } //end else if doodle
            }//end if type increment
        }//end for i
    }//end for j
}

void Board::stepForward(int& ants, int& doods) {
/*  this does an entire time step for us:
    1. Move doodle - try to eat ant, otherwise go in directions
    2. Move ant in direction
    3. Kill doodles if haven't eaten in 3 steps
    4. Breed critters */

    int eat_ants = 0;
    int dead_doods = 0;
    int new_ants = 0;
    int new_doods = 0;
    int total_ants = 0;
    int total_doods = 0;

    resetMove();

	display();
	std::cout << "Initial board for time step displayed!\n";

    //doodle move block
    moveCrits(DOODLE, eat_ants);
    display();
    std::cout << "Doodles moved!\n";

    //ant move block
    moveCrits(ANT, eat_ants);
    display();
    std::cout << "Ants moved!\n";

    //doodle kill block
    inquisition(dead_doods);

    //breed block
    spawncamp(new_ants, new_doods);

    //get total numbers
    count(total_ants, total_doods);
    ants = total_ants;
    doods = total_doods;

    std::cout << "\nTIME STEP TOTALS:\n";
    std::cout << "Ants eaten: " << eat_ants << std::endl;
    std::cout << "New ants: " << new_ants << std::endl;
    std::cout << "Dead doodlebugs: " << dead_doods << std::endl;
    std::cout << "New doodlebugs: " << new_doods << std::endl;
    std::cout << "\nTotal ants: " << total_ants << std::endl;
    std::cout << "Total doodlebugs: " << total_doods << std::endl;
}

Critter* Board::retrieve(int x, int y) const {
    if ((x >= 0) && (x < SIZE) && (y >= 0) && (y < SIZE)) {
        return grid[x][y];
    } else {
        return NULL;
    }
}

Position Board::randomPos() const {
    Position p;
    p.x = rand() % SIZE;
    p.y = rand() % SIZE;
    return p;
}

Move Board::randomMov() const {
    return static_cast<Move>(rand() % 4);
    //static_cast converts enum Move into an int for us
    //so that we can randomize our movement without a
    //bunch of overhead!
}

//Private Functions
void Board::create(critType critKind, int counter) {
    int critCount = 0;

    while (critCount < counter) {
        Position p = randomPos();

        if (grid[p.x][p.y] == NULL) {
            critCount++;

            if (critKind == ANT) {
                new Ant(this, p.x, p.y);
            } else if (critKind == DOODLE) {
                new Doodle(this, p.x, p.y);
            }//end if/else kind of critter
        }//end if space is empty
    }//end while
}

void Board::resetMove() {
    for (unsigned int i = 0; i < SIZE; i++) {
        for (unsigned int j = 0; j < SIZE; j++) {
            if (grid[i][j] != NULL) {
                grid[i][j]->setMoved(false);
            }//end if
        }//end for j
    }//end for i
}

void Board::moveCrits(critType kind, int& counter) {
    for (unsigned int i = 0; i < SIZE; i++) {
        for (unsigned int j = 0; j < SIZE; j++) {
            if (grid[i][j] != NULL) {
                if(grid[i][j]->type() == kind && !(grid[i][j]->hasMoved())) {
                    grid[i][j]->move(counter);
                }//end if it hasn't already moved
            }//end if != NULL
        }//end for j
    }//end for i
}

//Amongst our weaponry are such diverse elements as:
//fear, surprise, ruthless efficiency, an almost fanatical devotion to the Pope, and nice red uniforms...
void Board::inquisition(int& counter) {
    for (unsigned int i = 0; i < SIZE; i++) {
        for (unsigned int j = 0; j < SIZE; j++) {
            if ((grid[i][j] != NULL) && grid[i][j]->dead(counter)) {
                delete grid[i][j];
                grid[i][j] = NULL;
                counter++;
            }//end if
        }//end for j
    }//end for i

    if (counter != 0) {
        display();
        std::cout << "Corpses cleared!\n";
    }
}

void Board::spawncamp(int& ants, int& doods) {
    for (unsigned int i = 0; i < SIZE; i++) {
        for (unsigned int j = 0; j < SIZE; j++) {
            if (grid[i][j] != NULL) {
                if (grid[i][j]->type() == ANT) {
                    grid[i][j]->breed(ants);
                } else if (grid[i][j]->type() == DOODLE) {
                    grid[i][j]->breed(doods);
                }
            }//end if
        }//end for j
    }//end for i

    if ((ants != 0) || (doods != 0)) {
        display();
        std::cout << "Breeding done!\n";
    }
}
