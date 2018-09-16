#include "screen.h"

Screen::Screen(ScreenManager *manager, SDL_Renderer *ren)
{
    this->manager = manager;
    this->ren = ren;
}