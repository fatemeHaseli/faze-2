#ifndef _block
#define _block

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class block
{
    private:

        unsigned int xpos;
        unsigned int ypos;

        Texture shape;
        Sprite shape_main;

        void main ();

    public:

        void set_Texture(string);
        
        void set_xpos (unsigned int);
        void set_ypos (unsigned int);

        unsigned int get_xpos () const;
        unsigned int get_ypos () const;

        Sprite get_shape_main () const;
};

#endif