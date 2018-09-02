#ifndef SDL2_H
    #define SDL2_H
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#endif

class ScreenManager;

class Screen
{
public:
    Screen(ScreenManager *manager);
    virtual void handleInput() = 0;
    virtual void update(float dt) = 0;
    virtual void render(SDL_Renderer *ren) = 0;
    virtual void dispose() = 0;
private:
    ScreenManager *manager;
};