#include <string>
#include <stdio.h>
#include <iostream>
#ifndef SCREEN_H
#define SCREEN_H
#include "screen.h"
#endif
#ifndef SCREEN_MENU_H
#define SCREEN_MENU_H
#include "screen_menu.h"
#endif

#define FPS 60

using namespace std;

void calculate_frame_rate(Uint32 starting_tick)
{
    if ((1000 / FPS) > SDL_GetTicks() - starting_tick)
    {
        SDL_Delay((1000 / FPS) - (SDL_GetTicks() - starting_tick));
    }
}

int main(int argc, char const *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        cout << "SDL_Init Error" << SDL_GetError() << endl;
        return 1;
    }

    // Creamos una ventana
    SDL_Window *win = SDL_CreateWindow("Prueba", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 144, 256, SDL_WINDOW_SHOWN);
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
    /*stack<Screen *> pantallas;
    ScreenMenu *sc1 = new ScreenMenu(nullptr);
    ScreenMenu *sc2 = new ScreenMenu(nullptr);
    pantallas.push(sc1);
    pantallas.push(sc2);

    cout << "Tam:" << pantallas.size() << endl;*/

    ScreenManager *manager = new ScreenManager();
    ScreenMenu *sc1 = new ScreenMenu(manager, ren);
    manager->push(sc1);



    bool running = true;
    SDL_Event event;
    Uint32 starting_tick;
    while (running)
    {
        starting_tick = SDL_GetTicks();
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
                break;
            }
        }
        manager->handle_input(&event);
        manager->update(SDL_GetTicks() - starting_tick);
        manager->render(ren);

        calculate_frame_rate(starting_tick);
    }
    cout << "Saliendo..." << endl;

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
