#include "room.hpp"

void room::set_pos(unsigned int xpos, unsigned int ypos)
{
    (*this).xpos = xpos;
    (*this).ypos = ypos;
}

void room::set_name (string name)
{
    (*this).name = name;
}

void room::set_capacity(unsigned int capacity)
{
    (*this).capacity = capacity;
}

void room::set_length (unsigned int xLength, unsigned int yLength)
{
    (*this).xLength = xLength;
    (*this).yLength = yLength;

    (*this).enter_length ();
}

void room::enter_length ()
{
    (*this).endx = xpos + xLength;
    (*this).endy = ypos + yLength;
}

void room::set_Texture (string shape)
{
    (*this).shape.loadFromFile (shape);
}
Sprite room::get_shapeMain ()
{
    shape_main = Sprite ((*this).shape);

    shape_main.setPosition (this->get_xpos (), this->get_ypos ());
    
    return shape_main;
}