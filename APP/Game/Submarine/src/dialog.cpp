#include "dialog.h"
#include "QLabel"
#include "game.h"

extern Game *game;

Dialog::Dialog()
{
    resize(game->width()/3,game->height()/3);
}
