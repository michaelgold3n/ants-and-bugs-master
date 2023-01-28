//
//  FemaleRat.cpp
//  INHERITANCE_AND_POLYMORPHISM
//
//  Created by Kristjan Thorsteinsson on 01/04/14.
//  Copyright (c) 2014 Kristjan Thorsteinsson. All rights reserved.
//

#include "Windows.h"
#include "FemaleRat.h"
#include "MaleRat.h"
#include "Rodent.h"
using namespace std;

FemaleRat::FemaleRat(World* aWorld, int xcoord, int ycoord, bool ad) : Rodent(aWorld, xcoord, ycoord)
{
    isPregnant = false;
    DeliverBabyTicks = 0;
    adult = ad;
    adult_ticks = 3;
    infected = false;
    immune = false;
}

FemaleRat::FemaleRat(World* aWorld, int xcoord, int ycoord) : Rodent(aWorld, xcoord, ycoord)
{
    adult = true;
    infected = false;
    immune = false;
}

void FemaleRat::move()
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
    
   /* if(world->getAt(x, y + 1) != NULL)
    {
        if(world->getAt(x, y + 1)->getType() == MALERAT)
        {
            death_ticks = 0;
            delete world->getAt(x, y + 1);
            movesTo(x, y + 1);
            return;
        }
    }
    
    if(world->getAt(x, y - 1) != NULL)
    {
        if(world->getAt(x, y - 1)->getType() == MALERAT)
        {
            death_ticks = 0;
            delete world->getAt(x, y - 1);
            movesTo(x, y - 1);
            return;
        }
    }
    
    if(world->getAt(x - 1, y) != NULL)
    {
        if(world->getAt(x - 1, y)->getType() == MALERAT)
        {
            death_ticks = 0;
            delete world->getAt(x - 1, y);
            movesTo(x - 1, y);
            return;
        }
    }
    if(world->getAt(x + 1, y) != NULL)
    {
        if(world->getAt(x + 1, y)->getType() == MALERAT)
        {
            death_ticks = 0;
            delete world->getAt(x + 1, y);
            movesTo(x + 1, y);
            return;
        }
 }*/
    
    Move mover = world->randomMove();
    switch (mover)
    {
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

void FemaleRat::generateOffspring(int whereX, int whereY)
{
    srand(time(NULL));
    int sex = rand() % 2;


    if (sex == 1)
    {
        PlaySound(TEXT("C:\\Users\\Amos\\Desktop\\Programming Stuff\\Rodent Project\\Sound Files\\cry.wav"), NULL, SND_FILENAME | SND_ASYNC);
        new FemaleRat(this->world, whereX, whereY, false);
        isPregnant = false;
    }

    if (sex == 0)
    {
        PlaySound(TEXT("C:\\Users\\Amos\\Desktop\\Programming Stuff\\Rodent Project\\Sound Files\\cry.wav"), NULL, SND_FILENAME | SND_ASYNC);
        new MaleRat(this->world, whereX, whereY, false);
        isPregnant = false;
    }


}

void FemaleRat::breed()
{
    if (isPregnant && DeliverBabyTicks == 0)
    {
        breedAtAdjacentCell();
        isPregnant = false;
        adult = true;
    }
}


bool FemaleRat::isDead()
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


bool FemaleRat::getImmune()
{
    return immune;
}

RodentType FemaleRat::getType() const
{
    return FEMALERAT;
}


char FemaleRat::representation()const
{

    if (isPregnant == false && adult == true && immune == true && infected == false)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        return 233;
    }
    if (isPregnant == false && adult == true && infected == true)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        return 233;
    }
    if (isPregnant && adult == true)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        return 48 + DeliverBabyTicks;
    }
    if (adult == true && infected == false)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        return 233;
    }
    if (adult == false)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        return 237;
    }

}

bool FemaleRat::getAdult()
{
    return adult;
}

int FemaleRat::size() const
{
    return 30;
}

bool FemaleRat::in_range(int xx, int yy)
{
    return (xx >= 0) && (xx < WORLDSIZE) && (yy >= 0) && (yy < WORLDSIZE);
}