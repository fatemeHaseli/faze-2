#include "block.hpp"

void block::set_Texture(string shape)
{
    (*this).shape.loadFromFile (shape);
}
        
void block::set_xpos (unsigned int xpos)
{
    (*this).xpos = xpos;

    main ();
}
void block::set_ypos (unsigned int ypos)
{
    (*this).ypos = ypos;

    main ();
}

unsigned int block::get_xpos () const
{
    return (*this).xpos;
}
unsigned int block::get_ypos () const
{
    return (*this).ypos;
}

void block::main ()
{
    shape_main = Sprite ((*this).shape);

    shape_main.setPosition (xpos, ypos);
}

Sprite block::get_shape_main () const
{
    return (*this).shape_main;
}