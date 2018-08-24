//board.hpp

#ifndef _WORLD_HPP_
#define _WORLD_HPP_

#include "critter.hpp"

enum Move { UP = 0, DOWN, LEFT, RIGHT };
//there's a konami code joke here somewhere!

const int SIZE = 20;
const int ANTS = 100;
const int DOODLES = 5;
const int ANT_BREED = 3;
const int DOODLE_BREED = 8;
const int DEAD_DOODLE = 3;

struct Position {
    int x;
    int y;
};

class Board {
public:
    Board(unsigned int); //seed val
    ~Board();

    void set(int, int, Critter*);
    void display() const;
    void count(int&, int&) const;
    void stepForward(int&, int&);

    Critter* retrieve(int, int) const;
    Position randomPos() const;
    Move randomMov() const;

private: 
    Critter* grid[SIZE][SIZE];

	void create(critType, int);
    void moveCrits(critType, int&);
    void resetMove();
    void inquisition(int&); //nobody expects it -> scrubs the board of corpses
    void spawncamp(int&, int&);
};

#endif