//doodle.hpp

#ifndef _DOODLE_HPP_
#define _DOODLE_HPP_

#include <iostream>
#include "board.hpp"
#include "critter.hpp"

class Doodle: public Critter {
public:
    Doodle(Board*, int, int);

    void move(int&);
    void breed(int&);

    bool dead(int&) const;
    bool inRange(int, int);
    critType type() const;
    char symbol() const;

private:
    void generate(int, int);

    int deathTimer;
};

#endif