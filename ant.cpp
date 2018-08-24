//ant.cpp
//Implementation for the Ant class.

#include <iostream>
#include <cstdlib>
#include "ant.hpp"
#include "critter.hpp"
#include "board.hpp"

//Public functions
//Constructor -> invokes Critter constructor
Ant::Ant(Board* bread, int xpos, int ypos) : Critter(bread, xpos, ypos) {}
Ant::~Ant() {}

void Ant::move(int& counter) {
    breedTimer++;
    counter += 0;
    Move mauve = board->randomMov();

    switch(mauve) {
        case UP:
            if ((board->retrieve(x, y - 1) == NULL) && inRange(x, y - 1)) {
                moves(x, y - 1);
            }
            break;
        case DOWN:
            if ((board->retrieve(x, y + 1) == NULL) && inRange(x, y + 1)) {
                moves(x, y + 1);
            }
            break;
        case LEFT:
            if ((board->retrieve(x - 1, y) == NULL) && inRange(x - 1, y)) {
                moves(x - 1, y);
            }
            break;
        case RIGHT:
            if ((board->retrieve(x + 1, y) == NULL) && inRange(x + 1, y)) {
                moves(x + 1, y);
            }
            break;
        default:
            break;
    }
}

void Ant::breed(int& count) {
    if (breedTimer >= ANT_BREED) {
        spawnAdjacent();
        count++;
    }
}

bool Ant::dead(int& counter) const {
    counter += 0;
    return false;
}

bool Ant::inRange(int xpos, int ypos) {
    return ((xpos >= 0) && (xpos < SIZE) && (ypos >= 0) && (ypos < SIZE));
}

critType Ant::type() const {
    return ANT;
}

char Ant::symbol() const {
    return 'O';
}

//Private functions
void Ant::generate(int xpos, int ypos) {
    new Ant(this->board, xpos, ypos);
    breedTimer = 0;
}
