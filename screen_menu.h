#ifndef SCREEN_H
    #define SCREEN_H
    #include "screen.h"
#endif
#ifndef SCREEN_MANAGER_H
    #define SCREEN_MANAGER_H
    #include "screenmanager.h"
#endif


class ScreenMenu : public Screen
{
public:
    ScreenMenu(ScreenManager* manager);
    void handleInput() override;
    void update(float dt) override;
    void render(SDL_Renderer* ren) override;
    void dispose() override;
};