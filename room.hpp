#ifndef _room
#define _room

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

using namespace std;

class room
{
    private:

        unsigned int xpos, ypos;
        unsigned int xLength, yLength;
        unsigned int endx, endy;

        string name;

        unsigned int capacity;

        Texture shape;
        Sprite shape_main;

    public:

        void set_pos(unsigned int, unsigned int);
        void set_name (string);
        void set_capacity(unsigned int);
        void set_length (unsigned int, unsigned int);
        void enter_length ();

        unsigned int get_xpos() const { return xpos; }
        unsigned int get_ypos() const { return ypos; }
        string get_name() const { return name; }
        unsigned int get_capacity() const { return capacity; }
        unsigned int get_xlength() const { return xLength; }
        unsigned int get_ylength() const { return yLength; }

        void set_Texture (string);
        Sprite get_shapeMain ();
};

#endif