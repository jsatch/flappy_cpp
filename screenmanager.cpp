#include "screenmanager.h"

ScreenManager::ScreenManager()
{
    this->pila = new stack<Screen*>();
}
void ScreenManager::render(SDL_Renderer *ren)
{
    
}
void ScreenManager::push(Screen *screen)
{
    this->pila->push(screen)
}
void ScreenManager::pop()
{
    this->pila->pop()->dispose();
}
void ScreenManager::set(Screen *screen)
{
}
void ScreenManager::update(float dt)
{
}
void ScreenManager::render(SDL_Renderer *ren)
{
}