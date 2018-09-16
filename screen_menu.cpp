#include "screen_menu.h"

ScreenMenu::ScreenMenu(ScreenManager *manager, SDL_Renderer* ren) :Screen(manager, ren)
{
    SDL_GetRendererOutputSize(ren, &this->width, &this->height);

    SDL_Surface* surBackground = IMG_Load("resources/bg.png");
    if (surBackground == nullptr){
        cout << "IMG_Load Background Error" << SDL_GetError() << endl;
        return;
    }
    SDL_Texture* texBg = SDL_CreateTextureFromSurface(ren, surBackground);
    SDL_FreeSurface(surBackground);

    if (texBg == nullptr){
        cout << "SDL_CreateTextureFromSurface Background Error" << SDL_GetError() << endl;
        return;
    }

    SDL_Surface* surButton = IMG_Load("resources/button_play.png");
    if (surButton == nullptr){
        cout << "IMG_Load Button Play Error" << SDL_GetError() << endl;
        return;
    }
    this->sprButton = new Sprite(
        (this->width / 2) - (surButton->clip_rect.w / 2),
        (this->height / 2) - (surButton->clip_rect.h / 2),
        surButton->clip_rect.w,
        surButton->clip_rect.h);
    SDL_Texture* texButton = SDL_CreateTextureFromSurface(ren, surButton);
    SDL_FreeSurface(surButton);
    
    if (texButton == nullptr){
        cout << "SDL_CreateTextureFromSurface Button Error" << SDL_GetError() << endl;
        return;
    }
    this->sprButton->set_texture(texButton);


    this->sprBackground = new Sprite(0,0, this->width, this->height);
    this->sprBackground->set_texture(texBg);
    
}

void ScreenMenu::handleInput(SDL_Event* event)
{
    if (event->type == SDL_MOUSEBUTTONDOWN)
    {
        cout << "Evento SDL_MOUSEBUTTONDOWN" << endl;
        ScreenPlay* screen = new ScreenPlay(this->manager, this->ren);
        this->manager->push(screen);
    }
}
void ScreenMenu::update(Uint32 dt)
{

}
void ScreenMenu::render()
{
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, this->sprBackground->get_texture(), NULL, this->sprBackground->get_rect());
    SDL_RenderCopy(ren, this->sprButton->get_texture(), NULL, this->sprButton->get_rect());
    SDL_RenderPresent(ren);


    /*int w_total, h_total;

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
    SDL_RenderPresent(ren);*/

}
void ScreenMenu::dispose()
{

}