#ifndef _patient
#define _patient

#include "room.hpp"
#include "patientInf.hpp"

class patient : public room
{
    private:

        struct patientInf patientInfO;

        string direction;

        unsigned int speed = 5;

    public:

        array<pair<unsigned int, unsigned int>, 48> front_position;
        array<pair<unsigned int, unsigned int>, 48> down_position;
        array<pair<unsigned int, unsigned int>, 48> back_position;
        array<pair<unsigned int, unsigned int>, 48> up_position;

        void move_x_pos ();
        void move_x_neg ();

        void move_y_pos ();
        void move_y_neg ();

        void fixPositions ();

        void set_speed (unsigned int speed){ this->speed = speed; }
        unsigned int get_speed (){ return (*this).speed; }

        void set_direction (string direction) { this->direction = direction; }
        string get_direction () const { return direction; }

        void set_Age (unsigned int age) {this->patientInfO.Age = age;}
        unsigned int get_Age ();

        void set_name (string name) { this->patientInfO.name = name; }
        string get_name () { return this->patientInfO.name; }

        void set_patientFor (string);
        string get_patientFor ();

        bool set_sex (string);
        string get_sex () { return this->patientInfO.sex; }
};

#endif