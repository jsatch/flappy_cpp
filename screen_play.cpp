#include "screen_play.h"

ScreenPlay::ScreenPlay(ScreenManager *manager, SDL_Renderer *ren) :Screen(manager, ren)
{
    // Calculando alto y ancho
    SDL_GetRendererOutputSize(ren, &this->width, &this->height);

    // Cargando Texturas

    SDL_Surface* surBackground = IMG_Load("resources/bg.png");
    if (surBackground == nullptr)
    {
        cout << "IMG_Load Background Error" << SDL_GetError() << endl;
        return;
    }
    SDL_Texture* texBackground = SDL_CreateTextureFromSurface(ren, surBackground);
    SDL_FreeSurface(surBackground);
    if (texBackground == nullptr)
    {
        cout << "Texture Background Error" << SDL_GetError() << endl;
        return;
    }

    SDL_Surface* surGround = IMG_Load("resources/ground.png");
    if (surGround == nullptr)
    {
        cout << "IMG_Load Ground Error" << SDL_GetError() << endl;
        return;
    }
    SDL_Texture* texGround = SDL_CreateTextureFromSurface(ren, surGround);
    SDL_FreeSurface(surGround);
    if (texGround == nullptr)
    {
        cout << "Texture Ground Error" << SDL_GetError() << endl;
        return;
    }

    // Creando Sprites
    sprBackground = new Sprite(0, 0, this->width, this->height);
    sprGround = new Sprite(0, this->height - 80, 240, 80);
    sprBackground->set_texture(texBackground);
    sprGround->set_texture(texGround);


}
void ScreenPlay::handleInput(SDL_Event *event)
{
        
}
void ScreenPlay::update(Uint32 dt)
{

}
void ScreenPlay::render()
{
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, this->sprBackground->get_texture(), NULL, this->sprBackground->get_rect());
    SDL_RenderCopy(ren, this->sprGround->get_texture(), NULL, this->sprGround->get_rect());
    SDL_RenderPresent(ren);
}
void ScreenPlay::dispose()
{

}