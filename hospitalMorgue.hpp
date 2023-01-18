#ifndef _hospitalMorgue
#define _hospitalMorgue

#include "room.hpp"

class hospitalMorgue : public room
{
    private:

        unsigned int numOfIn;

        array<pair<unsigned int, unsigned int>, 16> availabePlaces;
        unsigned int index = 0;
        unsigned int maxIndex = 16;

        pair<unsigned int, unsigned int> GoTo;
        string point;

    public:

        bool set_numOfIn();

        unsigned int get_numOfIn() const { return numOfIn; }

        void set_availabePlaces();

        pair<unsigned int, unsigned int> get_availabePlace();

        void goTo ();

        pair <unsigned int, unsigned int> get_goTo () { return GoTo; }
        string get_point () { return point; }
};

#endif