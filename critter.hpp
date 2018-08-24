//critter.hpp

#ifndef _CRITTER_HPP_
#define _CRITTER_HPP_

enum critType { ANT = 0, DOODLE };

class Board; //this is a forward declaration

class Critter {
public:
    Critter(Board*, int, int);
    virtual ~Critter();

    virtual void move(int&) = 0;
    virtual void breed(int&) = 0;

    virtual critType type() const = 0;
    virtual char symbol() const = 0;
    virtual bool dead(int&) const = 0;

    void setMoved(bool);

    bool inRange(int, int);
    bool hasMoved() const;

protected:
    virtual void generate(int, int) = 0;

    void moves(int, int);
    void spawnAdjacent();

    int x;
    int y;
    int breedTimer;
    bool moved;
    Board* board;
};

#endif