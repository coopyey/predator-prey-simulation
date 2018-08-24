//doodle.cpp
//Implementation for doodlebugs.

#include "doodle.hpp"
#include "critter.hpp"

//Public functions
//Constructor
Doodle::Doodle(Board* bread, int xpos, int ypos) : Critter(bread, xpos, ypos) {
    deathTimer = 0;
}

void Doodle::move(int& eatenAnts) {
    breedTimer++;
    deathTimer++;

    //eating movements
    if ((board->retrieve(x, y + 1) != NULL) && (board->retrieve(x, y + 1)->type() == ANT)) {
        eatenAnts++;
        deathTimer = 0;
        delete board->retrieve(x, y + 1);
        moves(x, y + 1);
        return;
    }

    if ((board->retrieve(x, y - 1) != NULL) && (board->retrieve(x, y - 1)->type() == ANT)) {
        eatenAnts++;
        deathTimer = 0;
        delete board->retrieve(x, y - 1);
        moves(x, y - 1);
        return;
    }

    if ((board->retrieve(x + 1, y) != NULL) && (board->retrieve(x + 1, y)->type() == ANT)) {
        eatenAnts++;
        deathTimer = 0;
        delete board->retrieve(x + 1, y);
        moves(x + 1, y);
        return;
    }

    if ((board->retrieve(x - 1, y) != NULL) && (board->retrieve(x - 1, y)->type() == ANT)) {
        eatenAnts++;
        deathTimer = 0;
        delete board->retrieve(x - 1, y);
        moves(x - 1, y);
        return;
    }

    //non eating movements
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

void Doodle::breed(int& counter) {
    if (breedTimer >= DOODLE_BREED) {
        spawnAdjacent();
        counter++;
    }
}

bool Doodle::dead(int& counter) const {
    if (deathTimer >= DEAD_DOODLE) {
        return true;
        counter++;
    } else {
        return false;
    }
}

bool Doodle::inRange(int xpos, int ypos) {
    return ((xpos >= 0) && (xpos < SIZE) && (ypos >= 0) && (ypos < SIZE));
}

critType Doodle::type() const {
    return DOODLE;
}

char Doodle::symbol() const {
    return 'X';
}

//Private functions
void Doodle::generate(int xpos, int ypos) {
    new Doodle(this->board, xpos, ypos);
    breedTimer = 0;
}
