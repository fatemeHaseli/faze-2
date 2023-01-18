#include "patient.hpp"

void patient::move_x_pos ()
{
    (*this).set_pos (((*this).get_xpos () + speed), (*this).get_ypos ());

    (*this).fixPositions ();
}
void patient::move_x_neg ()
{
    (*this).set_pos (((*this).get_xpos () - speed), (*this).get_ypos ());

    (*this).fixPositions ();
}

void patient::move_y_pos ()
{
    (*this).set_pos (((*this).get_xpos ()), (*this).get_ypos () + speed);

    (*this).fixPositions ();
}
void patient::move_y_neg ()
{
    (*this).set_pos (((*this).get_xpos ()), (*this).get_ypos () - speed);

    (*this).fixPositions ();
}

void patient::fixPositions ()
{
    pair <unsigned int, unsigned int> temp_position_1;
    pair <unsigned int, unsigned int> temp_position_2;
    pair <unsigned int, unsigned int> temp_position_3;
    pair <unsigned int, unsigned int> temp_position_4;

    for (unsigned int i = 0; i < 48; i++)
    {
        temp_position_1.first = (*this).get_xpos () + 50;
        temp_position_1.second = (*this).get_ypos () + (i + 1);

        front_position[i] = temp_position_1;

        temp_position_2.first = (*this).get_xpos () + (i + 1);
        temp_position_2.second = (*this).get_ypos () + 50;

        down_position[i] = temp_position_2;

        temp_position_3.first = (*this).get_xpos ();
        temp_position_3.second = (*this).get_ypos () + (i + 1);

        back_position[i] = temp_position_3;
    
        temp_position_4.first = (*this).get_xpos () + (i + 1);
        temp_position_4.second = (*this).get_ypos ();

        up_position[i] = temp_position_4;
    }
}

unsigned int patient::get_Age ()
{
    return this->patientInfO.Age;
}

bool patient::set_sex (string sex)
{
    if (sex == 'M')
    {
        this->patientInfO.sex = 'M';

        return true;
    }
    else if (sex == 'F')
    {
        this->patientInfO.sex = 'F';

        return true;
    }
    else
    {
        return false;
    }
}

void patient::set_patientFor (string patientFor)
{
    if (patientFor == "badpos")
    {
        patientInfO.patientForO = BADPOS;
    }
    else if (patientFor == "needsurgery")
    {
        patientInfO.patientForO = NEEDSURGERY;
    }
    else if (patientFor == "needrest")
    {
        patientInfO.patientForO = NEEDREST;
    }
    else if (patientFor == "dead")
    {
        patientInfO.patientForO = DEAD;
    }
    else if (patientFor == "needWC")
    {
        patientInfO.patientForO = NEEDWC;
    }
    else if (patientFor == "wait")
    {
        patientInfO.patientForO = WAIT;
    }
}

string patient::get_patientFor ()
{
    if (patientInfO.patientForO == BADPOS)
    {
        return "badpos";
    }
    else if (patientInfO.patientForO == NEEDSURGERY)
    {
        return "needsurgery";
    }
    else if (patientInfO.patientForO == NEEDREST)
    {
        return "needrest";
    }
    else if (patientInfO.patientForO == DEAD)
    {
        return "dead";
    }
    else if (patientInfO.patientForO == NEEDWC)
    {
        return "needWC";
    }
    else if (patientInfO.patientForO == WAIT)
    {
        return "wait";
    }
}