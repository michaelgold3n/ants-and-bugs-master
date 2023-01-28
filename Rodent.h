#ifndef ORGANISM_H
#define ORGANISM_H

enum RodentType {MALERAT, FEMALERAT};

// forward declaration
class World;

class Rodent {
    public:

        int death_ticks;

        // to hold true false statement about rodent being infected
        bool infected;
        
        bool immune;

        // to hold true or false statment about rodent being adult
        bool adult;

        virtual bool getAdult() = 0;

        virtual bool getImmune() = 0;

        Rodent();

        // Create an Rodent at the given coordinates.
        Rodent(World* aWorld, int xcoord, int ycoord);
        virtual ~Rodent() { }

        // In the given world moves this Rodent.
        virtual void move() = 0;

        // Makes this organism Rodent.
        virtual void breed() = 0;

        // Returns the type of this Rodent.
        virtual RodentType getType() const = 0;

        // Flags this Rodent as moved or not.
        void setMoved(bool hasMoved);

        // The character representation of this Rodent.
        virtual char representation() const = 0;

        // The size of this Rodent.
        virtual int size() const = 0;

        // Has this Rodent moved in this time slot or not?
        bool hasMoved() const;

        // Returns true if Rodent is dead, false otherwise.
        virtual bool isDead() = 0;

    
        bool in_range(int xx, int yy);
    
    protected:
        // Generates an offspring at the given position.
        virtual void generateOffspring(int whereX, int whereY) = 0;

        // Moves this Rodent from coordinates (x,y) to (xNew,yNew).
        void movesTo(int xNew, int yNew);

        // Breeds a new Rodent at an adjacent cell. Tries to produce one new
        // Rodent in UP, DOWN, LEFT, or RIGHT cell (in that order).  Makes
        // sure not to breed off the grid.
        void breedAtAdjacentCell();

        // This Rodent's x position in the world.
        int x;

        // This Rodent's y position in the world.
        int y;

        // Has moved this turn?
        bool moved;

        //Number of ticks until adulthood.
        int adult_ticks;

        // A pointer to the world in which this organism lives.
        World* world;
    private:
};

#endif // ORGANISM_H
