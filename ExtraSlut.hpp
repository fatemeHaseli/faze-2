#ifndef _ExtraSlut
#define _ExtraSlut

#include "room.hpp"

class ExtraSlut : public room
{
    private:
    
        unsigned int numOfIn;

        unsigned int whichOne;

        array<pair<unsigned int, unsigned int>, 28> availabePlaces;
        unsigned int index = 0;
        unsigned int maxIndex = 28;

    public:
        bool set_numOfIn ();
        
        unsigned int get_numOfIn () const { return numOfIn; }

        void set_availabePlaces();

        pair<unsigned int, unsigned int> get_availabePlace();

        void set_whichOne (unsigned int whichOne) { this->whichOne = whichOne; }
        unsigned int get_whichOne () const { return this->whichOne; }

        void goTo ();
};

#endif