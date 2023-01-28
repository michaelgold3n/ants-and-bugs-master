//
//  FemaleRat.h
//  INHERITANCE_AND_POLYMORPHISM
//
//  Created by Kristjan Thorsteinsson on 01/04/14.
//  Copyright (c) 2014 Kristjan Thorsteinsson. All rights reserved.
//

#ifndef INHERITANCE_AND_POLYMORPHISM_Bug
#define INHERITANCE_AND_POLYMORPHISM_Bug

#include <iostream>

#include "World.h"
#include "Rodent.h"

class FemaleRat : public Rodent
{
public:
    
    bool adult;
    bool isPregnant;
    int DeliverBabyTicks;
    
    bool getAdult();
    bool getImmune();

    FemaleRat();
    FemaleRat(World* aWorld, int xcoord, int ycoord);
    FemaleRat(World* aWorld, int xcoord, int ycoord, bool ad);

    bool AlreadyPregnant;

    // In the given world moves this Rodent.
    void move();
    
    // Makes this organism Rodent.
    void breed();
    
    // Returns the type of this Rodent.
    RodentType getType() const;
    
    // The character representation of this Rodent.
    char representation() const;
    
    // The size of this Rodent.
    int size() const;

    // Returns true if Rodent is dead, false otherwise.
    bool isDead();
    
    bool in_range(int xx, int yy);
    
private:
    
    void generateOffspring(int whereX, int whereY);
};

#endif /* defined(__INHERITANCE_AND_POLYMORPHISM__FemaleRat__) */
