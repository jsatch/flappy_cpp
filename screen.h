#ifndef SDL2_H
    #define SDL2_H
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#endif

class ScreenManager;

class Screen
{
    protected:
        int width, height;
        ScreenManager *manager;
        SDL_Renderer *ren;
    public:
        Screen(ScreenManager *manager, SDL_Renderer *ren);
        virtual void handleInput(SDL_Event* event) = 0;
        virtual void update(Uint32 dt) = 0;
        virtual void render() = 0;
        virtual void dispose() = 0;
};