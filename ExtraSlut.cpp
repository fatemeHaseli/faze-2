#include "ExtraSlut.hpp"

bool ExtraSlut::set_numOfIn ()
{
    if (numOfIn < get_capacity())
    {
        numOfIn++;

        return true;
    }
    else
        return false;
}

void ExtraSlut::set_availabePlaces()
{
    if (this->get_whichOne () == 1)
    {
        availabePlaces[0].first = 800;
        availabePlaces[0].second = 50;

        availabePlaces[1].first = 850;
        availabePlaces[1].second = 50;

        availabePlaces[2].first = 900;
        availabePlaces[2].second = 50;

        availabePlaces[3].first = 950;
        availabePlaces[3].second = 50;

        availabePlaces[4].first = 1000;
        availabePlaces[4].second = 50;

        availabePlaces[5].first = 1050;
        availabePlaces[5].second = 50;

        availabePlaces[6].first = 1100;
        availabePlaces[6].second = 50;

        availabePlaces[7].first = 800;
        availabePlaces[7].second = 100;

        availabePlaces[8].first = 850;
        availabePlaces[8].second = 100;

        availabePlaces[9].first = 900;
        availabePlaces[9].second = 100;

        availabePlaces[10].first = 950;
        availabePlaces[10].second = 100;

        availabePlaces[11].first = 1000;
        availabePlaces[11].second = 100;

        availabePlaces[12].first = 1050;
        availabePlaces[12].second = 100;

        availabePlaces[13].first = 1100;
        availabePlaces[13].second = 100;

        availabePlaces[14].first = 800;
        availabePlaces[14].second = 150;

        availabePlaces[15].first = 850;
        availabePlaces[15].second = 150;

        availabePlaces[16].first = 900;
        availabePlaces[16].second = 150;

        availabePlaces[17].first = 950;
        availabePlaces[17].second = 150;

        availabePlaces[18].first = 1000;
        availabePlaces[18].second = 150;

        availabePlaces[19].first = 1050;
        availabePlaces[19].second = 150;    

        availabePlaces[20].first = 1100;
        availabePlaces[20].second = 150; 

        availabePlaces[21].first = 800;
        availabePlaces[21].second = 200;

        availabePlaces[22].first = 850;
        availabePlaces[22].second = 200;

        availabePlaces[23].first = 900;
        availabePlaces[23].second = 200;

        availabePlaces[24].first = 950;
        availabePlaces[24].second = 200;

        availabePlaces[25].first = 1000;
        availabePlaces[25].second = 200;

        availabePlaces[26].first = 1050;
        availabePlaces[26].second = 200;    

        availabePlaces[27].first = 1100;
        availabePlaces[27].second = 200;
    } 
    else if (this->get_whichOne () == 2)
    {
        availabePlaces[0].first = 800;
        availabePlaces[0].second = 700;

        availabePlaces[1].first = 850;
        availabePlaces[1].second = 700;

        availabePlaces[2].first = 900;
        availabePlaces[2].second = 700;

        availabePlaces[3].first = 950;
        availabePlaces[3].second = 700;

        availabePlaces[4].first = 1000;
        availabePlaces[4].second = 700;

        availabePlaces[5].first = 1050;
        availabePlaces[5].second = 700;

        availabePlaces[6].first = 1100;
        availabePlaces[6].second = 700;

        availabePlaces[7].first = 800;
        availabePlaces[7].second = 650;

        availabePlaces[8].first = 850;
        availabePlaces[8].second = 650;

        availabePlaces[9].first = 900;
        availabePlaces[9].second = 650;

        availabePlaces[10].first = 950;
        availabePlaces[10].second = 650;

        availabePlaces[11].first = 1000;
        availabePlaces[11].second = 650;

        availabePlaces[12].first = 1050;
        availabePlaces[12].second = 650;

        availabePlaces[13].first = 1100;
        availabePlaces[13].second = 650;

        availabePlaces[14].first = 800;
        availabePlaces[14].second = 600;

        availabePlaces[15].first = 850;
        availabePlaces[15].second = 600;

        availabePlaces[16].first = 900;
        availabePlaces[16].second = 600;

        availabePlaces[17].first = 950;
        availabePlaces[17].second = 600;

        availabePlaces[18].first = 1000;
        availabePlaces[18].second = 600;

        availabePlaces[19].first = 1050;
        availabePlaces[19].second = 600;    

        availabePlaces[20].first = 1100;
        availabePlaces[20].second = 600; 

        availabePlaces[21].first = 800;
        availabePlaces[21].second = 550;

        availabePlaces[22].first = 850;
        availabePlaces[22].second = 550;

        availabePlaces[23].first = 900;
        availabePlaces[23].second = 550;

        availabePlaces[24].first = 950;
        availabePlaces[24].second = 550;

        availabePlaces[25].first = 1000;
        availabePlaces[25].second = 550;

        availabePlaces[26].first = 1050;
        availabePlaces[26].second = 550;    

        availabePlaces[27].first = 1100;
        availabePlaces[27].second = 550;
    }
}

pair<unsigned int, unsigned int> ExtraSlut::get_availabePlace()
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