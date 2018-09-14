#include <SDL2/SDL.h>
#include <stack>
#ifndef SCREEN_H
#define SCREEN_H
#include "screen.h"
#endif
using namespace std;

class ScreenManager
{
public:
    ScreenManager();
    void render(SDL_Renderer *ren);
    void push(Screen *screen);
    void pop();
    void set(Screen *screen);
    void update(Uint32 dt);
    void handle_input(SDL_Event* event);
private:
    stack<Screen*> *pila;
};