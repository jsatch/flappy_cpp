#include <SDL2/SDL.h>
#include <stack>
#include "screen.h"

using namespace std;

class ScreenManager
{
public:
    ScreenManager();
    void render(SDL_Renderer *ren );
    void push(Screen *screen);
    void pop();
    void set(Screen *screen);
    void update(float dt);
    void render(SDL_Renderer *ren);
private:
    stack<Screen*> *pila;
};