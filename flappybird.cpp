#include <string>
#include <stdio.h>
#include <iostream>
#include <stack>
#ifndef SDL2_H
    #define SDL2_H
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#endif
#ifndef SCREEN_H
  #define SCREEN_H
  #include "screen.h"
#endif
#ifndef SCREEN_MENU_H
    #define SCREEN_MENU_H
    #include "screen_menu.h"
#endif

using namespace std;

int main(int argc, char const *argv[])
{
    /*if (SDL_Init(SDL_INIT_VIDEO) != 0)
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
    }*/
    stack<Screen*> pantallas;
    ScreenMenu* sc1 = new ScreenMenu(nullptr);
    ScreenMenu* sc2 = new ScreenMenu(nullptr); 
    pantallas.push(sc1);
    pantallas.push(sc2);

    cout << "Tam:" << pantallas.size() << endl;




    
    return 0;
}
