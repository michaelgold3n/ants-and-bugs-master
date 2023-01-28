#ifndef WORLD_H
#define WORLD_H
#include "Rodent.h"

// The possible moves
enum Move {UP = 0, DOWN, LEFT, RIGHT};

// The size of this world
const int WORLDSIZE = 10;

// Number of initial ants
const int INITIAL_MALERATS = 5;

// Number of initial bugs
const int INITIAL_FEMALERATS = 5;


struct Position
{
    int x;
    int y;
};

class World
{
    public:

        // function to see if rat is infected
        void InfectedRat();

        // Constructor: creates and initializes this world. the seed is used for
        // seeding the random behaviour.
        World(unsigned int seed);

        // Destructor.
        ~World();

        // Returns the Rodents at the given coordinates.
        Rodent* getAt(int x, int y) const;

        // Sets the Rodent org at position (x,y).
        void setAt(int x, int y, Rodent* org);

        // Displays this world.
        void display() const;

        // Simulates one time step in this world.
        void simulateOneStep();

        // Returns a random position in the grid.
        Position randomPosition() const;

        // Returns a random move (UP, DOWN, LEFT or RIGHT).
        Move randomMove() const;

    private:
        // The grid in which the Rodents live. According the to image below,
        // the correct iteration order through grid starts at the top left
        // corner (i.e. grid[0][0]), loops through one column at a time and ends
        // at the bottom right corner (i.e. grid[WORLDSIZE-1][WORLDSIZE-1]).
        //
        // grid[0, 0]          , grid[1, 0],      ...,      grid[WORLDSIZE-1, 0]
        // grid[0, 1]          , grid[1, 1],      ...,      grid[WORLDSIZE-1, 1]
        //    .                                                     .
        //    .                                                     .
        //    .                                                     .
        // grid[0, WORLDSIZE-2], grid[1, WORLDSIZE-2], ..., grid[WORLDSIZE-1, WORLDSIZE-2]
        // grid[0, WORLDSIZE-1], grid[1, WORLDSIZE-1], ..., grid[WORLDSIZE-1, WORLDSIZE-1]
		//
		// (See e.g. the destructor for correct iteration through the grid)
        Rodent* grid[WORLDSIZE][WORLDSIZE];

        // Randomly create `count` many Rodents of type `orgType`.  This
        // method uses the parameterized constructor in Male Rats and Female Rats.
        void createRodents(RodentType orgType, int count);

        // Reset all Rodents to not moved. This is necessary because later we
        // iterate through the grid starting from the top left moving to the
        // bottom right looking for an Rodent to move. Say if an Rodent
        // moves down, we don't want to move the Rodent again when we reach
        // it.
        void resetRodents();

        // Make every Rodent in this world of type aType move. Make sure to
        // to iterate through grid in order as specified above and only move an
        // Rodent if it hasn't moved already.
        void moveRodents(RodentType aType);

        // Remove all dead Rodents from this world. Iterates through the grid
        // and uses the method Rodent::isDead() to test if an Rodent is
        // dead.
        void cleanup();

        // Make every Rodent in this world breed. Make sure to iterate
        // through grid in order as specified above and to only breed Rodents
        // that have moved, since breeding places new Rodents on the map we
        // don't want to try and breed those.
        void ifitistimetogivebirth();

};

#endif // WORLD_H
