#include <iostream>
#include <cstdlib>  // for rand
#include "World.h"
#include "MaleRat.h"
#include "FemaleRat.h"
#include "Windows.h"
#include "Rodent.h"
using namespace std;

///////////////////
// Public functions
///////////////////

// Default constructor: creates and initializes the world
// the seed is used for seeding the random behaviour.
World::World(unsigned int seed) {
    // seed the random generator
    srand(seed);
    // Create an empty world
    for (int i = 0; i < WORLDSIZE; i++) {
        for (int j = 0; j < WORLDSIZE; j++) {
            grid[i][j] = NULL;
        }
    }
    // creates the male rats
    createRodents(MALERAT, INITIAL_MALERATS);
    // creates the female rats
    createRodents(FEMALERAT, INITIAL_FEMALERATS);
}

// Deallocate memory allocated to rodents in this world.
World::~World() {
    for (int i = 0; i < WORLDSIZE; i++) {
        for (int j = 0; j < WORLDSIZE; j++) {
            if (grid[i][j] != NULL) {
                delete grid[i][j];
            }
        }
    }
}

// Return the rodents at the given coordinates
// If the coordinates are not valid, returns NULL
Rodent* World::getAt(int x, int y) const {
    if ((x >= 0) && (x < WORLDSIZE) && (y >= 0) && (y < WORLDSIZE)) {
        return grid[x][y];
    } else {
        return NULL;
    }
}

// Sets the entry at x,y to the value passed in.
void World::setAt(int x, int y, Rodent* org) {
    if ((x >= 0) && (x < WORLDSIZE) && (y >= 0) && (y < WORLDSIZE)) {
        grid[x][y] = org;
    }
}

// Displays the world in ASCII.
void World::display() const 
{
    int numMaleRats = 0;
    int numMaleBabyRats = 0;
    int numFemaleRats = 0;
    int numFemaleBabyRats = 0;
    int numInfectedMaleRats = 0;
    int numInfectedFemaleRats = 0;
    int numImmuneRats = 0;
    cout << endl << endl;
    for (int j = 0; j < WORLDSIZE; j++) 
    {
        for (int i = 0; i < WORLDSIZE; i++)
        {
            if (grid[i][j] == NULL) 
            {
                cout << " ";
            } else {
                if (grid[i][j]->getType() == MALERAT && grid[i][j]->getAdult() == true)
                {
                    numMaleRats++;
                }
                if (grid[i][j]->getType() == FEMALERAT && grid[i][j]->getAdult() == true)
                {
                    numFemaleRats++;
                }
                if (grid[i][j]->getType() == MALERAT && grid[i][j]->getAdult() == false)
                {
                    numMaleBabyRats++;
                }
                if (grid[i][j]->getType() == FEMALERAT && grid[i][j]->getAdult() == false)
                {
                    numFemaleBabyRats++;
                }

                if (grid[i][j]->getType() == FEMALERAT && grid[i][j]->getAdult() == true && grid[i][j]->infected == true)
                {
                    numInfectedFemaleRats++;
                }
                if (grid[i][j]->getType() == MALERAT && grid[i][j]->getAdult() == true && grid[i][j]->infected == true)
                {
                    numInfectedMaleRats++;
                }
                if (grid[i][j] != NULL && grid[i][j]->immune == true)
                {
                    numImmuneRats++;
                }
                //if (grid[i][j]->getType() == FEMALERAT)
                //{
                //    FemaleRat* f = (FemaleRat*)grid[i][j];
                //    if (f->isPregnant == false && f->infected == false && f->immune == true && f->adult == true)
                //    {
                //        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                //        //return 233;
                //    }
                //    if (f->isPregnant == false && f->adult == true && f->infected == true)
                //    {
                //        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                //        //return 233;
                //    }
                //    if (f->isPregnant && f->adult == true)
                //    {
                //        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                //        //return 48 + DeliverBabyTicks;
                //    }
                //    if (f->adult == true && f->infected == false)
                //    {
                //        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                //        //return 233;
                //    }
                //    if (f->adult == false)
                //    {
                //        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
                //        //return 237;
                //    }
                //}
                //if (grid[i][j]->getType() == MALERAT)
                //{
                //    MaleRat* m = (MaleRat*)grid[i][j];
                //    if (m->adult == true && m->infected == false && m->immune == true)
                //    {
                //        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                //        //return 225;
                //    }
                //    if (m->adult == true && m->infected == false)
                //    {
                //        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                //        //return 225;
                //    }
                //    if (m->infected == true)
                //    {
                //        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                //        //return 225;
                //    }
                //    if (m->adult == false) 
                //    {
                //        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                //        //return 227;
                //    }
                //}
                cout << grid[i][j]->representation();
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
        }
        cout << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);;
    cout << endl << "Male Rats ("<< char(225) <<"): " << numMaleRats;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << endl <<"Female Rats (" << char(233) << "): " << numFemaleRats;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << endl << "Male Baby Rats (" << char(227) << "): " << numMaleBabyRats;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    cout << endl << "Female Baby Rats (" << char(237) << "): " << numFemaleBabyRats;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << endl << "Infected Male Adult Rats: " << numInfectedMaleRats;
    cout << endl << "Infected Female Adult Rats: " << numInfectedFemaleRats;
    cout << endl << "Immune Rats: " << numImmuneRats;
}

void World::simulateOneStep() {
    // The main routine that simulates one turn in the world:
    // 1. move Male Rats
    // 2. move Female Rats
    // 3. make bugs starve (which happends under a certain condition)
    // 4. make the Rodents breed (again which happens under a certain
    // condition).

    // Reset all organisms to not moved
    resetRodents();

    // Move the Male Rats
    moveRodents(MALERAT);

    // Move the Female Rats
    moveRodents(FEMALERAT);

    // Make the Infected Rodents Die
    cleanup();

    //Make them breed
    ifitistimetogivebirth();
}

Position World::randomPosition() const {    // returns a random number in the range 0 to MAX-1
    Position p;
    p.x = rand() % WORLDSIZE;
    p.y = rand() % WORLDSIZE;
    return p;
}


Move World::randomMove() const {
    return static_cast<Move>(rand() % 4);
}

////////////////////
// Private functions
////////////////////

void World::createRodents(RodentType orgType, int count) 
{
    int rodCount = 0;
    while (rodCount < count) {
        Position p = randomPosition();

        // Only put ant in empty spot
        if (grid[p.x][p.y] == NULL) {
            rodCount++;
            if (orgType == MALERAT) {
                new MaleRat(this, p.x, p.y);   // Create a Male Rat and put it into the world
            }
            else if (orgType == FEMALERAT) {
                new FemaleRat(this, p.x, p.y);   // Create a Female Rat and put it into the world
            }
        }
    }
}

// Reset all Rodents to not moved
void World::resetRodents() {
    for(int i = 0; i < WORLDSIZE; i++)
    {
        for (int j = 0; j < WORLDSIZE; j++)
        {
            if(grid[i][j] != NULL)
            {
                grid[i][j]->setMoved(false);
            }
        }
    }
}

// Move all Rodents of type aType
void World::moveRodents(RodentType aType) 
{
    srand(time(NULL));
    int areyoupregnant = rand() % 2;
    int tryforpregnancyagain = rand() % 10;

    for(int i = 0; i < WORLDSIZE; i++)
    {
        for(int j = 0; j < WORLDSIZE; j++)
        {
            if(grid[i][j] != NULL)
            {
                if(grid[i][j]->getType() == aType && !(grid[i][j]->hasMoved()))
                {
                    if (grid[i][j]->getType() == FEMALERAT && grid[i][j]->getAdult() == true)
                    {
                        FemaleRat* f = (FemaleRat*)grid[i][j];
                        if (f->isPregnant)
                        {
                            f->DeliverBabyTicks--;
                        }
                    }
                    if (grid[i][j]->getType() == FEMALERAT && grid[i][j]->getAdult() == true)
                    {
                        if (grid[i][j]->infected == true)
                        {
                            // IS THERE MALE ON LEFT?
                            if (i > 0)
                            {
                                if (grid[i - 1][j] != NULL)
                                {
                                    if (grid[i - 1][j]->getType() == MALERAT && grid[i - 1][j]->getAdult() == true)
                                    {
                                        // IS HE INFECTED?
                                        MaleRat* m = (MaleRat*)grid[i - 1][j];
                                        if (grid[i - 1][j]->infected == false && grid[i - 1][j]->getImmune() == false)
                                        {
                                            m->infected = true;
                                            m->death_ticks = 10;
                                        }
                                    }
                                }
                            }
                            // IS THERE MALE ON RIGHT?
                            if (i < WORLDSIZE - 1)
                            {
                                if (grid[i + 1][j] != NULL)
                                {
                                    if (grid[i + 1][j]->getType() == MALERAT && grid[i + 1][j]->getAdult() == true)
                                    {
                                        // IS HE INFECTED?
                                        MaleRat* m = (MaleRat*)grid[i + 1][j];
                                        if (grid[i + 1][j]->infected == false && grid[i + 1][j]->getImmune() == false)
                                        {
                                            m->infected = true;
                                            m->death_ticks = 10;
                                        }
                                    }
                                }
                            }
                            // IS THERE MALE ON TOP RIGHT?
                            if (j > 0 && i < WORLDSIZE - 1)
                            {
                                if (grid[i + 1][j - 1] != NULL)
                                {
                                    if (grid[i + 1][j - 1]->getType() == FEMALERAT && grid[i + 1][j - 1]->getAdult() == true)
                                    {
                                        // IS HE INFECTED?
                                        MaleRat* m = (MaleRat*)grid[i + 1][j - 1];
                                        if (grid[i + 1][j - 1]->infected == false && grid[i+1][j-1]->getImmune() == false)
                                        {
                                            m->infected = true;
                                            m->death_ticks = 10;
                                        }
                                    }
                                }
                            }
                            // IS THERE MALE ON TOP LEFT?
                            if (j > 0 && i > 0)
                            {
                                if (grid[i - 1][j - 1] != NULL)
                                {
                                    if (grid[i - 1][j - 1]->getType() == FEMALERAT && grid[i - 1][j - 1]->getAdult() == true)
                                    {
                                        // IS HE INFECTED?
                                        MaleRat* m = (MaleRat*)grid[i - 1][j - 1];
                                        if (grid[i - 1][j - 1]->infected == false && grid[i - 1][j - 1]->getImmune() == false)
                                        {
                                            m->infected = true;
                                            m->death_ticks = 10;
                                        }
                                    }
                                }
                            }
                            // IS THERE MALE ON BOTTOM LEFT?
                            if (j < WORLDSIZE - 1 && i > 0)
                            {
                                if (grid[i - 1][j + 1] != NULL)
                                {
                                    if (grid[i - 1][j + 1]->getType() == FEMALERAT && grid[i - 1][j + 1]->getAdult() == true)
                                    {
                                        // IS HE INFECTED?
                                        MaleRat* m = (MaleRat*)grid[i - 1][j + 1];
                                        if (grid[i - 1][j + 1]->infected == false && grid[i - 1][j + 1]->getImmune() == false)
                                        {
                                            m->infected = true;
                                            m->death_ticks = 10;
                                        }
                                    }
                                }
                            }
                            // IS THERE MALE ON BOTTOM RIGHT?
                            if (j < WORLDSIZE - 1 && i < WORLDSIZE - 1)
                            {
                                if (grid[i + 1][j + 1] != NULL)
                                {
                                    if (grid[i + 1][j + 1]->getType() == FEMALERAT && grid[i + 1][j + 1]->getAdult() == true)
                                    {
                                        // IS HE INFECTED?
                                        MaleRat* m = (MaleRat*)grid[i + 1][j + 1];
                                        if (grid[i + 1][j + 1]->infected == false && grid[i + 1][j + 1]->getImmune() == false)
                                        {
                                            m->infected = true;
                                            m->death_ticks = 10;
                                        }
                                    }
                                }
                            }
                            // IS THERE MALE ON TOP?
                            if (j > 0)
                            {
                                if (grid[i][j - 1] != NULL)
                                {
                                    if (grid[i][j - 1]->getType() == FEMALERAT && grid[i][j - 1]->getAdult() == true)
                                    {
                                        // IS HE INFECTED?
                                        MaleRat* m = (MaleRat*)grid[i][j - 1];
                                        if (grid[i][j - 1]->infected == false && grid[i][j -1]->getImmune() == false)
                                        {
                                            m->infected = true;
                                            m->death_ticks = 10;
                                        }
                                    }
                                }
                            }
                            // IS THERE MALE ON BOTTOM?
                            if (j < WORLDSIZE - 1)
                            {
                                if (grid[i][j + 1] != NULL)
                                {
                                    if (grid[i][j + 1]->getType() == FEMALERAT && grid[i][j + 1]->getAdult() == true)
                                    {
                                        // IS HE INFECTED?
                                        MaleRat* m = (MaleRat*)grid[i][j + 1];
                                        if (grid[i][j + 1]->infected == false && grid[i][j + 1]->getImmune() == false)
                                        {
                                            m->infected = true;
                                            m->death_ticks = 10;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (grid[i][j]->getType() == MALERAT && grid[i][j]->getAdult() == true)
                    {
                        if (grid[i][j]->infected == true)
                        {
                            // IS THERE FEMALE ON LEFT?
                            if (i > 0)
                            {
                                if (grid[i - 1][j] != NULL)
                                {
                                    if (grid[i - 1][j]->getType() == FEMALERAT && grid[i - 1][j]->getAdult() == true)
                                    {
                                        // IS SHE INFECTED?
                                        FemaleRat* f = (FemaleRat*)grid[i - 1][j];
                                        if (grid[i - 1][j]->infected == false && grid[i - 1][j]->getImmune() == false)
                                        {
                                            f->infected = true;
                                            f->death_ticks = 10;
                                        }
                                    }
                                }
                            }
                            // IS THERE FEMALE ON RIGHT?
                            if (i < WORLDSIZE - 1)
                            {
                                if (grid[i + 1][j] != NULL)
                                {
                                    if (grid[i + 1][j]->getType() == FEMALERAT && grid[i + 1][j]->getAdult() == true)
                                    {
                                        // IS SHE INFECTED?
                                        FemaleRat* f = (FemaleRat*)grid[i + 1][j];
                                        if (grid[i + 1][j]->infected == false && grid[i + 1][j]->getImmune() == false)
                                        {
                                            f->infected = true;
                                            f->death_ticks = 10;
                                        }
                                    }
                                }
                            }
                            // IS THERE FEMALE ON TOP RIGHT?
                            if (j > 0 && i < WORLDSIZE - 1)
                            {
                                if (grid[i + 1][j - 1] != NULL)
                                {
                                    if (grid[i + 1][j - 1]->getType() == FEMALERAT && grid[i + 1][j - 1]->getAdult() == true)
                                    {
                                        // IS SHE INFECTED?
                                        FemaleRat* f = (FemaleRat*)grid[i + 1][j - 1];
                                        if (grid[i + 1][j - 1]->infected == false && grid[i + 1][j - 1]->getImmune() == false)
                                        {
                                            f->infected = true;
                                            f->death_ticks = 10;
                                        }
                                    }
                                }
                            }
                            // IS THERE FEMALE ON TOP LEFT?
                            if (j > 0 && i > 0)
                            {
                                if (grid[i - 1][j - 1] != NULL)
                                {
                                    if (grid[i - 1][j - 1]->getType() == FEMALERAT && grid[i - 1][j - 1]->getAdult() == true)
                                    {
                                        // IS SHE INFECTED?
                                        FemaleRat* f = (FemaleRat*)grid[i - 1][j - 1];
                                        if (grid[i - 1][j - 1]->infected == false && grid[i - 1][j - 1]->getImmune() == false)
                                        {
                                            f->infected = true;
                                            f->death_ticks = 10;
                                        }
                                    }
                                }
                            }
                            // IS THERE FEMALE ON BOTTOM LEFT?
                            if (j < WORLDSIZE - 1 && i > 0)
                            {
                                if (grid[i - 1][j + 1] != NULL)
                                {
                                    if (grid[i - 1][j + 1]->getType() == FEMALERAT && grid[i - 1][j + 1]->getAdult() == true)
                                    {
                                        // IS SHE INFECTED?
                                        FemaleRat* f = (FemaleRat*)grid[i - 1][j + 1];
                                        if (grid[i - 1][j + 1]->infected == false && grid[i - 1][j + 1]->getImmune() == false)
                                        {
                                            f->infected = true;
                                            f->death_ticks = 10;
                                        }
                                    }
                                }
                            }
                            // IS THERE FEMALE ON BOTTOM RIGHT?
                            if (j < WORLDSIZE - 1 && i < WORLDSIZE - 1)
                            {
                                if (grid[i + 1][j + 1] != NULL)
                                {
                                    if (grid[i + 1][j + 1]->getType() == FEMALERAT && grid[i + 1][j + 1]->getAdult() == true)
                                    {
                                        // IS SHE INFECTED?
                                        FemaleRat* f = (FemaleRat*)grid[i + 1][j + 1];
                                        if (grid[i + 1][j + 1]->infected == false && grid[i + 1][j + 1]->getImmune() == false)
                                        {
                                            f->infected = true;
                                            f->death_ticks = 10;
                                        }
                                    }
                                }
                            }
                            // IS THERE FEMALE ON TOP?
                            if (j > 0)
                            {
                                if (grid[i][j - 1] != NULL)
                                {
                                    if (grid[i][j - 1]->getType() == FEMALERAT && grid[i][j - 1]->getAdult() == true)
                                    {
                                        // IS SHE INFECTED?
                                        FemaleRat* f = (FemaleRat*)grid[i][j - 1];
                                        if (grid[i][j-1]->infected == false && grid[i][j - 1]->getImmune() == false)
                                        {
                                            f->infected = true;
                                            f->death_ticks = 10;
                                        }
                                    }
                                }
                            }
                            // IS THERE FEMALE ON BOTTOM?
                            if (j < WORLDSIZE - 1)
                            {
                                if (grid[i][j + 1] != NULL)
                                {
                                    if (grid[i][j + 1]->getType() == FEMALERAT && grid[i][j + 1]->getAdult() == true)
                                    {
                                        // IS SHE INFECTED?
                                        FemaleRat* f = (FemaleRat*)grid[i][j + 1];
                                        if (grid[i][j+1]->infected == false && grid[i][j + 1]->getImmune() == false)
                                        {
                                            f->infected = true;
                                            f->death_ticks = 10;
                                        }
                                    }
                                }
                            }
                        }
                        

                        //split
                        // 
                        // 
                        // 
                        // 
                        
                        // IS THERE FEMALE ON LEFT?
                        if (i > 0)
                        {
                            if (grid[i-1][j] != NULL)
                            {
                                if (grid[i-1][j]->getType() == FEMALERAT && grid[i-1][j]->getAdult() == true)
                                {
                                    // IS SHE PREGNANT?
                                    FemaleRat* f = (FemaleRat*)grid[i-1][j];
                                    if (!f->isPregnant)
                                    {
                                        if (f->AlreadyPregnant == true && tryforpregnancyagain == 0)
                                        {
                                            f->isPregnant = true;
                                            f->DeliverBabyTicks = 3;
                                        }
                                        if (f->AlreadyPregnant == false && areyoupregnant == 0)
                                        {
                                            f->isPregnant = true;
                                            f->DeliverBabyTicks = 3;
                                            f->AlreadyPregnant = true;
                                        }
                                    }
                                }
                            }
                        }
                         // IS THERE FEMALE ON RIGHT?
                        if (i < WORLDSIZE - 1)
                        {
                            if (grid[i + 1][j] != NULL)
                            {
                                if (grid[i + 1][j]->getType() == FEMALERAT && grid[i+1][j]->getAdult() == true)
                                {
                                    // IS SHE PREGNANT?
                                    FemaleRat* f = (FemaleRat*)grid[i + 1][j];
                                    if (!f->isPregnant)
                                    {
                                        if (f->AlreadyPregnant == true && tryforpregnancyagain == 0)
                                        {
                                            f->isPregnant = true;
                                            f->DeliverBabyTicks = 3;
                                        }
                                        if (f->AlreadyPregnant == false && areyoupregnant == 0)
                                        {
                                            f->isPregnant = true;
                                            f->DeliverBabyTicks = 3;
                                            f->AlreadyPregnant = true;
                                        }
                                    }
                                }
                            }
                        }
                         // IS THERE FEMALE ON TOP RIGHT?
                        if (j > 0 && i < WORLDSIZE - 1)
                        {
                            if (grid[i + 1][j - 1] != NULL)
                            {
                                if (grid[i + 1][j - 1]->getType() == FEMALERAT && grid[i+1][j-1]->getAdult() == true)
                                {
                                    // IS SHE PREGNANT?
                                    FemaleRat* f = (FemaleRat*)grid[i + 1][j - 1];
                                    if (!f->isPregnant)
                                    {
                                        if (f->AlreadyPregnant == true && tryforpregnancyagain == 0)
                                        {
                                            f->isPregnant = true;
                                            f->DeliverBabyTicks = 3;
                                        }
                                        if (f->AlreadyPregnant == false && areyoupregnant == 0)
                                        {
                                            f->isPregnant = true;
                                            f->DeliverBabyTicks = 3;
                                            f->AlreadyPregnant = true;
                                        }
                                    }
                                }
                            }
                        }
                         // IS THERE FEMALE ON TOP LEFT?
                        if (j > 0 && i > 0)
                        {
                            if (grid[i - 1][j - 1] != NULL)
                            {
                                if (grid[i - 1][j - 1]->getType() == FEMALERAT && grid[i - 1][j - 1]->getAdult() == true)
                                {
                                    // IS SHE PREGNANT?
                                    FemaleRat* f = (FemaleRat*)grid[i - 1][j - 1];
                                    if (!f->isPregnant)
                                    {
                                        if (f->AlreadyPregnant == true && tryforpregnancyagain == 0)
                                        {
                                            f->isPregnant = true;
                                            f->DeliverBabyTicks = 3;
                                        }
                                        if (f->AlreadyPregnant == false && areyoupregnant == 0)
                                        {
                                            f->isPregnant = true;
                                            f->DeliverBabyTicks = 3;
                                            f->AlreadyPregnant = true;
                                        }
                                    }
                                }
                            }
                        }
                         // IS THERE FEMALE ON BOTTOM LEFT?
                        if (j < WORLDSIZE - 1 && i > 0)
                        {
                            if (grid[i - 1][j + 1] != NULL)
                            {
                                if (grid[i - 1][j + 1]->getType() == FEMALERAT && grid[i - 1][j + 1]->getAdult() == true)
                                {
                                    // IS SHE PREGNANT?
                                    FemaleRat* f = (FemaleRat*)grid[i - 1][j + 1];
                                    if (!f->isPregnant)
                                    {
                                        if (f->AlreadyPregnant == true && tryforpregnancyagain == 0)
                                        {
                                            f->isPregnant = true;
                                            f->DeliverBabyTicks = 3;
                                        }
                                        if (f->AlreadyPregnant == false && areyoupregnant == 0)
                                        {
                                            f->isPregnant = true;
                                            f->DeliverBabyTicks = 3;
                                            f->AlreadyPregnant = true;
                                        }
                                    }
                                }
                            }
                        }
                         // IS THERE FEMALE ON BOTTOM RIGHT?
                        if (j < WORLDSIZE - 1 && i < WORLDSIZE - 1)
                        {
                            if (grid[i + 1][j + 1] != NULL)
                            {
                                if (grid[i + 1][j + 1]->getType() == FEMALERAT && grid[i + 1][j + 1]->getAdult() == true)
                                {
                                    // IS SHE PREGNANT?
                                    FemaleRat* f = (FemaleRat*)grid[i + 1][j + 1];
                                    if (!f->isPregnant)
                                    {
                                        if (f->AlreadyPregnant == true && tryforpregnancyagain == 0)
                                        {
                                            f->isPregnant = true;
                                            f->DeliverBabyTicks = 3;
                                        }
                                        if (f->AlreadyPregnant == false && areyoupregnant == 0)
                                        {
                                            f->isPregnant = true;
                                            f->DeliverBabyTicks = 3;
                                            f->AlreadyPregnant = true;
                                        }
                                    }
                                }
                            }
                        }
                         // IS THERE FEMALE ON TOP?
                        if (j > 0)
                        {
                            if (grid[i][j-1] != NULL)
                            {
                                if (grid[i][j-1]->getType() == FEMALERAT && grid[i][j-1]->getAdult() == true)
                                {
                                    // IS SHE PREGNANT?
                                    FemaleRat* f = (FemaleRat*)grid[i][j-1];
                                    if (!f->isPregnant)
                                    {
                                        if (f->AlreadyPregnant == true && tryforpregnancyagain == 0)
                                        {
                                            f->isPregnant = true;
                                            f->DeliverBabyTicks = 3;
                                        }
                                        if (f->AlreadyPregnant == false && areyoupregnant == 0)
                                        {
                                            f->isPregnant = true;
                                            f->DeliverBabyTicks = 3;
                                            f->AlreadyPregnant = true;
                                        }
                                    }
                                }
                            }
                        }
                        // IS THERE FEMALE ON BOTTOM?
                        if (j < WORLDSIZE - 1)
                        {
                            if (grid[i][j + 1] != NULL)
                            {
                                if (grid[i][j + 1]->getType() == FEMALERAT && grid[i][j+1]->getAdult() == true)
                                {
                                    // IS SHE PREGNANT?
                                    FemaleRat* f = (FemaleRat*)grid[i][j + 1];
                                    if (!f->isPregnant)
                                    {
                                        if (f->AlreadyPregnant == true && tryforpregnancyagain == 0)
                                        {
                                            f->isPregnant = true;
                                            f->DeliverBabyTicks = 3;
                                        }
                                        if (f->AlreadyPregnant == false && areyoupregnant == 0)
                                        {
                                            f->isPregnant = true;
                                            f->DeliverBabyTicks = 3;
                                            f->AlreadyPregnant = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    grid[i][j]->move();
                }
            }
        }
    }
}

// Remove all dead Rodents from this world.
void World::cleanup()
{
    for (int i = 0; i < WORLDSIZE; i++) 
    {
        for (int j = 0; j < WORLDSIZE; j++) 
        {
            // Kill off any Rodents that are infected and not immune
            if (grid[i][j] != NULL && grid[i][j]->isDead() == true)
            {
                PlaySound(TEXT("C:\\Users\\Amos\\Desktop\\Programming Stuff\\Rodent Project\\Sound Files\\oof.wav"), NULL, SND_FILENAME | SND_ASYNC);
                delete grid[i][j];
                grid[i][j] = NULL;
            }
        }
    }
}

// Make the Rodents Breed
void World::ifitistimetogivebirth() 
{
    for(int i = 0; i < WORLDSIZE; i++)
    {
        for(int j = 0; j < WORLDSIZE; j++)
        {
            if(grid[i][j] != NULL)
            {
                if (grid[i][j]->getType() == FEMALERAT)
                {
                    grid[i][j]->breed();
                }
            }
        }
    }
}


// Make the Rats Infected
void World::InfectedRat()
{
    for (int i = 0; i < WORLDSIZE; i++)
    {
        for (int j = 0; j < WORLDSIZE; j++)
        {
            if (grid[i][j] != NULL)
            {
                if (grid[i][j]->getAdult() == true && grid[i][j]->getType() == FEMALERAT)
                {
                    FemaleRat* f = (FemaleRat*)grid[i][j];
                    if (f->infected == false && f->immune == false)
                    {
                        f->infected = true;
                        f->death_ticks = 10;
                    }
                }
                if (grid[i][j]->getAdult() == true && grid[i][j]->getType() == MALERAT)
                {
                    MaleRat* m = (MaleRat*)grid[i][j];
                    if (m->infected == false && m->immune == false)
                    {
                        m->infected = true;
                        m->death_ticks = 10;
                    }
                }
            }
        }
    }
}


