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
#include <vector>

using namespace std;

class ScreenPlay : public Screen
{
    private:
        const int TUBE_SPACING = 50;
        const int TUBE_COUNT = 4;
        const int TUBE_WIDTH = 26;
        const int GROUND_OFFSET = -40;
        const int GROUND_VELOCITY = 1;
        Sprite* sprBackground;
        Sprite* sprGround1;
        Sprite* sprGround2;
        vector<Tube> tubes;

        void reposition(Tube* tube);
    public:
        ScreenPlay(ScreenManager* manager, SDL_Renderer* ren);
        void handleInput(SDL_Event* event) override;
        void update(Uint32 dt) override;
        void render() override;
        void dispose() override;
};