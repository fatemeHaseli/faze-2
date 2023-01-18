#include "restSlut.hpp"

bool restSlut::set_numOfIn ()
{
    if (numOfIn < get_capacity())
    {
        numOfIn++;

        return true;
    }
    else
        return false;
}

void restSlut::set_availabePlaces()
{
    availabePlaces[0].first = 550;
    availabePlaces[0].second = 700;

    availabePlaces[1].first = 600;
    availabePlaces[1].second = 700;

    availabePlaces[2].first = 650;
    availabePlaces[2].second = 700;

    availabePlaces[3].first = 700;
    availabePlaces[3].second = 700;

    availabePlaces[4].first = 550;
    availabePlaces[4].second = 650;

    availabePlaces[5].first = 600;
    availabePlaces[5].second = 650;

    availabePlaces[6].first = 650;
    availabePlaces[6].second = 650;

    availabePlaces[7].first = 700;
    availabePlaces[7].second = 650;

    availabePlaces[8].first = 550;
    availabePlaces[8].second = 600;

    availabePlaces[9].first = 600;
    availabePlaces[9].second = 600;

    availabePlaces[10].first = 650;
    availabePlaces[10].second = 600;

    availabePlaces[11].first = 700;
    availabePlaces[11].second = 600;

    availabePlaces[12].first = 550;
    availabePlaces[12].second = 550;

    availabePlaces[13].first = 600;
    availabePlaces[13].second = 550;

    availabePlaces[14].first = 650;
    availabePlaces[14].second = 550;

    availabePlaces[15].first = 700;
    availabePlaces[15].second = 550;
}

pair<unsigned int, unsigned int> restSlut::get_availabePlace()
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

void restSlut::goTo ()
{
    this->GoTo.first = 625;
    this->GoTo.second = 175;

    this->point = "down";
}