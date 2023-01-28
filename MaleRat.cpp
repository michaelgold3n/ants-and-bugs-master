//
//  MaleRat.cpp
//  INHERITANCE_AND_POLYMORPHISM
//
//  Created by Kristjan Thorsteinsson on 01/04/14.
//  Copyright (c) 2014 Kristjan Thorsteinsson. All rights reserved.

#include <cstdlib>
#include "Windows.h"
#include <iostream>
#include "MaleRat.h"
#include "Rodent.h"
#include "World.h"
using namespace std;

MaleRat::MaleRat(World* aWorld, int xcoord, int ycoord, bool ad) : Rodent(aWorld, xcoord, ycoord)
{
    adult = ad;
    adult_ticks = 3;
    infected = false;
    immune = false;
}

MaleRat::MaleRat(World* aWorld, int xcoord, int ycoord) : Rodent(aWorld, xcoord, ycoord)
{
    adult = true;
    infected = false;
    immune = false;
}


void MaleRat::move()
{
    adult_ticks--;
    
    if (infected == true && immune == false)
    {
        death_ticks--;
    }

    if (adult_ticks == 0)
    {
        adult = true;
    }

    Move mover = world->randomMove();
    switch (mover){
        case UP:
            if(world->getAt(x, y + 1) == NULL && in_range(x, y + 1))
            {
                movesTo(x, y + 1);
            }
            break;
        case DOWN:
            if(world->getAt(x, y - 1) == NULL && in_range(x, y - 1))
            {
                movesTo(x, y - 1);
            }
            break;
        case LEFT:
            if(world->getAt(x - 1, y) == NULL && in_range(x - 1, y))
            {
                movesTo(x - 1, y);
            }
            break;
        case RIGHT:
            if(world->getAt(x + 1, y) == NULL && in_range(x + 1, y))
            {
                movesTo(x + 1, y);
            }
            break;
        default:
            break;
    }
}

void MaleRat::breed(){}

RodentType MaleRat::getType() const
{
    return MALERAT;
}

bool MaleRat::getAdult()
{
    return adult;
}

bool MaleRat::getImmune() 
{
    return immune;
}

char MaleRat::representation() const
{
    if (adult == true && immune == true && infected == false)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        return 225;
    }
    if (adult == true && infected == false)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        return 225;
    }
    if (infected == true)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        return 225;
    }
    if (adult == false)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        return 227;
    }
}

int MaleRat::size() const
{
    return 10;
}

bool MaleRat::in_range(int xx, int yy)
{
    return (xx >= 0) && (xx < WORLDSIZE) && (yy >= 0) && (yy < WORLDSIZE);
}

bool MaleRat::isDead()
{
    srand(time(NULL));
    int areyoudead = rand() % 10;
    if (death_ticks == 0 && infected == true && immune == false)
    {
        if (areyoudead == 0)
        {
            immune = true;
            infected = false;
            return false;
        }
        else
        {
            return true;
        }
    }
}

void MaleRat::generateOffspring(int whereX, int whereY)
{

}