#include "operatingRoom.hpp"

bool operatingRoom::set_numOfIn ()
{
    if (numOfIn < get_capacity())
    {
        numOfIn++;

        return true;
    }
    else
        return false;
}

void operatingRoom::set_availabePlaces()
{
    availabePlaces[0].first = 50;
    availabePlaces[0].second = 50;

    availabePlaces[1].first = 100;
    availabePlaces[1].second = 50;

    availabePlaces[2].first = 150;
    availabePlaces[2].second = 50;

    availabePlaces[3].first = 200;
    availabePlaces[3].second = 50;

    availabePlaces[4].first = 50;
    availabePlaces[4].second = 100;

    availabePlaces[5].first = 100;
    availabePlaces[5].second = 100;

    availabePlaces[6].first = 150;
    availabePlaces[6].second = 100;

    availabePlaces[7].first = 200;
    availabePlaces[7].second = 100;

    availabePlaces[8].first = 50;
    availabePlaces[8].second = 150;

    availabePlaces[9].first = 100;
    availabePlaces[9].second = 150;

    availabePlaces[10].first = 150;
    availabePlaces[10].second = 150;

    availabePlaces[11].first = 200;
    availabePlaces[11].second = 150;

    availabePlaces[12].first = 50;
    availabePlaces[12].second = 200;

    availabePlaces[13].first = 100;
    availabePlaces[13].second = 200;

    availabePlaces[14].first = 150;
    availabePlaces[14].second = 200;

    availabePlaces[15].first = 200;
    availabePlaces[15].second = 200;
}

pair<unsigned int, unsigned int> operatingRoom::get_availabePlace()
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

void operatingRoom::set_boarder ()
{
    for (unsigned int i = 0; i < 200; i++)
    {
        boarder[i].first = 50 + i;
        boarder[i].second = 250;
    }
}

void operatingRoom::goTo ()
{
    this->GoTo.first = 125;
    this->GoTo.second = 125;

    this->point = "up";
}