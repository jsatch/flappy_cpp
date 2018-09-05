#include <string>
#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#define FPS 60

using namespace std;

int main(int argc, char const *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        cout << "SDL_Init Error" << SDL_GetError() << endl;
        return 1;
    }

    // Creamos una ventana
    SDL_Window *win = SDL_CreateWindow("Prueba", 100,100, 1024, 800, SDL_WINDOW_SHOWN);
    if (win == nullptr){
        cout << "SDL_CreateWindow Error" << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    // Creamos un renderer (que es como el canvas que se mostrara)
    // Con -1 utiliza el driver de renderizado que esta definido por defecto.
    SDL_Renderer * ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr)
    {
        SDL_DestroyWindow(win);
        cout << "SDL_CreateRenderer Error" << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    SDL_Surface *screen = SDL_GetWindowSurface(win);
    if (screen == nullptr)
    {
        SDL_FreeSurface(screen);
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        cout << "SDL_CreateRenderer Error" << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event;
    Uint32 starting_tick;
    while(running)
    {
        starting_tick = SDL_GetTicks();
        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    SDL_FreeSurface(screen);
                    SDL_DestroyRenderer(ren);
                    SDL_DestroyWindow(win);
                    SDL_Quit();
                break;
            }
        }
        if (1000 / FPS > SDL_GetTicks() - starting_tick)
        {
            SDL_Delay((1000 / FPS) - SDL_GetTicks() - starting_tick);
        }
    }

    
    return 0;
}
