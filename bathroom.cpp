#include "bathroom.hpp"

bool bathroom::set_numOfIn ()
{
    if (numOfIn < get_capacity())
    {
        numOfIn++;

        return true;
    }
    else
        return false;
}

void bathroom::set_availabePlaces()
{
    if (get_sex () == 'M')
    {
        availabePlaces[0].first = 500;
        availabePlaces[0].second = 50;

        availabePlaces[1].first = 550;
        availabePlaces[1].second = 50;

        availabePlaces[2].first = 500;
        availabePlaces[2].second = 100;

        availabePlaces[3].first = 550;
        availabePlaces[3].second = 100;

        availabePlaces[4].first = 500;
        availabePlaces[4].second = 150;

        availabePlaces[5].first = 550;
        availabePlaces[5].second = 150;
    }
    else if (get_sex () == 'F')
    {
        availabePlaces[0].first = 650;
        availabePlaces[0].second = 50;

        availabePlaces[1].first = 700;
        availabePlaces[1].second = 50;

        availabePlaces[2].first = 650;
        availabePlaces[2].second = 100;

        availabePlaces[3].first = 700;
        availabePlaces[3].second = 100;

        availabePlaces[4].first = 650;
        availabePlaces[4].second = 150;

        availabePlaces[5].first = 700;
        availabePlaces[5].second = 150;
    }
}

pair<unsigned int, unsigned int> bathroom::get_availabePlace()
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

void bathroom::goTo ()
{
    if (this->get_sex () == 'M')
    {
        this->GoTo.first = 525;
        this->GoTo.second = 175;

        this->point = "up";
    }
    else if (this->get_sex () == 'F')
    {
        this->GoTo.first = 675;
        this->GoTo.second = 175;

        this->point = "up";
    }
}