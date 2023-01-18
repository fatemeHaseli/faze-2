#include "reception.hpp"

bool reception::set_numOfIn ()
{
    if (numOfIn < get_capacity())
    {
        numOfIn++;

        return true;
    }
    else
        return false;
}

void reception::set_availabePlaces()
{
    availabePlaces[0].first = 300;
    availabePlaces[0].second = 50;

    availabePlaces[1].first = 350;
    availabePlaces[1].second = 50;

    availabePlaces[2].first = 400;
    availabePlaces[2].second = 50;

    availabePlaces[3].first = 300;
    availabePlaces[3].second = 100;

    availabePlaces[4].first = 350;
    availabePlaces[4].second = 100;

    availabePlaces[5].first = 400;
    availabePlaces[5].second = 100;

    availabePlaces[6].first = 300;
    availabePlaces[6].second = 150;

    availabePlaces[7].first = 350;
    availabePlaces[7].second = 150;

    availabePlaces[8].first = 400;
    availabePlaces[8].second = 150;

    availabePlaces[9].first = 300;
    availabePlaces[9].second = 200;

    availabePlaces[10].first = 350;
    availabePlaces[10].second = 200;

    availabePlaces[11].first = 400;
    availabePlaces[11].second = 200;
}

pair<unsigned int, unsigned int> reception::get_availabePlace()
{
    pair<unsigned int, unsigned int> full_availabePlace;
    full_availabePlace.first = 0;
    full_availabePlace.second = 0;

    if (this->index < this->maxIndex)
    {
        index++;

        return this->availabePlaces[index - 1];
    }
    else
    {
        return full_availabePlace;
    }
}

void reception::goTo ()
{
    this->GoTo.first = 350;
    this->GoTo.second = 175;

    this->point = "up";
}