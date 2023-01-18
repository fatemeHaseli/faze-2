#include "game.hpp"
#include <string>

int main ()
{
    game Game;

    while (Game.isOpen())
    {
        Game.update ();
        Game.Render ();
    }

    return 0;
}
