#include "screenmanager.h"

ScreenManager::ScreenManager()
{
    this->pila = new stack<Screen*>();
}
void ScreenManager::render(SDL_Renderer *ren)
{
    this->pila->top()->render();
}
void ScreenManager::push(Screen *screen)
{
    this->pila->push(screen);
}
void ScreenManager::pop()
{
    Screen* screen = this->pila->top();
    screen->dispose();
    this->pila->pop();
}
void ScreenManager::set(Screen *screen)
{
    this->pop();
    this->push(screen);
}
void ScreenManager::update(Uint32 dt)
{
    this->pila->top()->update(dt);
}

void ScreenManager::handle_input(SDL_Event* event){
    this->pila->top()->handleInput(event);
}