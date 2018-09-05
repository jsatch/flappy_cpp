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

using namespace std;


class ScreenMenu : public Screen
{
public:
    ScreenMenu(ScreenManager* manager);
    void handleInput(SDL_Event* event) override;
    void update(float dt) override;
    void render(SDL_Renderer* ren) override;
    void dispose() override;
};