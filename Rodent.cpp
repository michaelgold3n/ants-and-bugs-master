#include <iostream>
#include "Rodent.h"
#include "World.h"


Rodent::Rodent(World* aWorld, int xcoord, int ycoord)
{
    adult = true;
    world = aWorld;
    x = xcoord;
    y = ycoord;
    moved = false;
    infected = false;
    world->setAt(x, y, this);
    //death_ticks = 10;
}

// flags the Rodent as moved or not
void Rodent::setMoved(bool hasMoved) {
    moved = hasMoved;
}


// has the Rodent moved or not?
bool Rodent::hasMoved() const {
    return moved;
}

// moves the Rodent from coordinates (x,y) to (xNew,yNew)
void Rodent::movesTo(int xNew, int yNew) {

        world->setAt(xNew, yNew, world->getAt(x, y));
    
        world->setAt(x, y, NULL);
        
        x = xNew;
        y = yNew;
    
    world->getAt(x, y)->setMoved(true);
}

// Breeds an Rodent at an adjacent cell. This method calls the
// generateOffspring() method.
void Rodent::breedAtAdjacentCell()  
{
    
    if((world->getAt(x, y + 1) == NULL) && in_range(x, y + 1))
    {
        generateOffspring(x, y + 1);
    }
    else if((world->getAt(x, y - 1) == NULL) && in_range(x, y - 1))
    {
        generateOffspring(x, y - 1);
    }
    else if((world->getAt(x - 1, y) == NULL)  && in_range(x - 1, y))
    {
        generateOffspring(x - 1, y);
    }
    else if((world->getAt(x + 1, y) == NULL)  && in_range(x + 1, y))
    {
        generateOffspring(x + 1, y);
    }

}


bool Rodent::in_range(int xx, int yy)
{
    return (xx >= 0) && (xx < WORLDSIZE) && (yy >= 0) && (yy < WORLDSIZE);
}
