#ifndef SCREEN_H
    #define SCREEN_H
    #include "screen.h"
#endif
#ifndef SCREEN_MANAGER_H
    #define SCREEN_MANAGER_H
    #include "screenmanager.h"
#endif
#ifndef IOSTREAM
    #define IOSTREAM
    #include <iostream>
#endif
#ifndef SPRITES_H
    #define SPRITES_H
    #include "sprites.h"
#endif
#ifndef SDL2_H
    #define SDL2_H
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#endif

using namespace std;


class ScreenMenu : public Screen
{
    private:
        Sprite *sprBackground;
        Sprite *sprButton;
        int width, height;
    public:
        ScreenMenu(ScreenManager* manager, SDL_Renderer* ren);
        void handleInput(SDL_Event* event) override;
        void update(Uint32 dt) override;
        void render(SDL_Renderer* ren) override;
        void dispose() override;
};