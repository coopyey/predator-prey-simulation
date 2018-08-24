//ant.hpp

#ifndef _ANT_HPP_
#define _ANT_HPP_

#include <iostream>
#include "critter.hpp"
#include "board.hpp"

class Ant: public Critter {
public:
    Ant(Board*, int, int);
    ~Ant();

    void move(int&);
    void breed(int&);

    bool dead(int&) const;
    bool inRange(int, int);
    critType type() const;
    char symbol() const;

private:
    void generate(int, int);
};

#endif