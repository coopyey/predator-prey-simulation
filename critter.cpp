//critter.cpp
//Virtual function for ants and doodlebugs.

#include <iostream>
#include "critter.hpp"
#include "board.hpp"

//Public functions
//Constructor
Critter::Critter(Board* z, int xpos, int ypos) {
    board = z;
    x = xpos;
    y = ypos;
    breedTimer = 0;
    moved = false;
    board->set(x, y, this);
}
Critter::~Critter() {}

void Critter::setMoved(bool isMove) {
    moved = isMove;
}

bool Critter::inRange(int isx, int isy) {
    return (isx >= 0) && (isx < SIZE) && (isy >= 0) && (isy < SIZE);
}

bool Critter::hasMoved() const {
    return moved;
}

//Protected Functions
void Critter::moves(int nx, int ny) {
    board->set(nx, ny, board->retrieve(x,y));
    board->set(x, y, NULL);

    x = nx;
    y = ny;

    board->retrieve(x, y)->setMoved(true);
}

void Critter::spawnAdjacent() {
    if((board->retrieve(x, y + 1) == NULL) && inRange(x, y + 1)) {
        generate(x, y + 1);
    } else if((board->retrieve(x, y - 1) == NULL) && inRange(x, y - 1)) {
        generate(x, y - 1);
    } else if((board->retrieve(x + 1, y) == NULL) && inRange(x + 1, y)) {
        generate(x + 1, y);
    } else if((board->retrieve(x - 1, y) == NULL) && inRange(x - 1, y)) {
        generate(x - 1, y);
    }
}