#ifndef _bathroom
#define _bathroom

#include "room.hpp"

class bathroom : public room
{
    private:

        unsigned int numOfIn;

        char sex;

        array<pair<unsigned int, unsigned int>, 6> availabePlaces;
        unsigned int index = 0;
        unsigned int maxIndex = 6;

        pair<unsigned int, unsigned int> GoTo;
        string point;

    public:

        bool set_numOfIn ();
        
        unsigned int get_numOfIn () const { return numOfIn; }

        void set_sex (char sex) { this->sex = sex; };

        char get_sex () const { return this->sex; }

        void set_availabePlaces();

        pair<unsigned int, unsigned int> get_availabePlace();

        void goTo ();

        pair <unsigned int, unsigned int> get_goTo () { return GoTo; }
        string get_point () { return point; }
};

#endif