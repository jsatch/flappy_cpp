#include "screen_menu.h"

ScreenMenu::ScreenMenu(ScreenManager *manager) :Screen(manager)
{
}

void ScreenMenu::handleInput(SDL_Event* event)
{
}
void ScreenMenu::update(float dt)
{
}
void ScreenMenu::render(SDL_Renderer* ren)
{
    int w_total, h_total;

    // Para obtener el tamano de la pantalla
    SDL_GetRendererOutputSize(ren, &w_total, &h_total);


    SDL_Surface* surface = SDL_CreateRGBSurface(0, 100, 100, 32, 0, 0 ,0 ,0);
    Uint32 rojo = SDL_MapRGB(surface->format, 255, 0, 0);
    SDL_FillRect(surface, NULL, rojo);

    if (surface == nullptr){
        cout << "SDL_CreateRGBSurface Error" << SDL_GetError() << endl;
        return;
    }
    SDL_Rect dest_rec;
    dest_rec.w = surface->clip_rect.w;
    dest_rec.h = surface->clip_rect.h;
    dest_rec.x = (w_total / 2) - (dest_rec.w / 2);
    dest_rec.y = (h_total / 2) - (dest_rec.h / 2);

    SDL_Texture* texture = SDL_CreateTextureFromSurface(ren, surface);
    SDL_FreeSurface(surface);
    
    SDL_RenderClear(ren);
    
    
    SDL_RenderCopy(ren, texture, NULL, &dest_rec);
    SDL_RenderPresent(ren);

}
void ScreenMenu::dispose()
{

}