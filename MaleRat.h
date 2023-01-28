//
//  MaleRat.h
//  INHERITANCE_AND_POLYMORPHISM
//
//  Created by Kristjan Thorsteinsson on 01/04/14.
//  Copyright (c) 2014 Kristjan Thorsteinsson. All rights reserved.
//

#ifndef INHERITANCE_AND_POLYMORPHISM_Ant
#define INHERITANCE_AND_POLYMORPHISM_Ant

#include <iostream>
#include "Rodent.h"
#include "World.h"

class MaleRat : public Rodent
{
public:

    bool adult;

    MaleRat(World* aWorld, int xcoord, int ycoord, bool ad);
    MaleRat(World* aWorld, int xcoord, int ycoord);

    bool getImmune();

    bool getAdult();


    // In the given world moves this Rodent.
    void move();
    
    // Makes this organism Rodent.
    void breed();
    
    // Returns the type of this Rodent.
    RodentType getType() const;
    
    // The character representation of this Rodent.
    char representation() const;
    
    // Returns true if Rodent is dead, false otherwise.
    bool isDead();

    // The size of this Rodent.
    int size() const;
    
    bool in_range(int xx, int yy);
    
private:
    
    void generateOffspring(int whereX, int whereY);
};

#endif /* defined(__INHERITANCE_AND_POLYMORPHISM__MaleRat__) */
