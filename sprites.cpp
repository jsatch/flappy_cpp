#include "sprites.h"

Sprite::Sprite(int x, int y, int width, int height)
{
    this->rect.x = x;
    this->rect.y = y;
    this->rect.w = width;
    this->rect.h = height;
}
Sprite::Sprite(SDL_Rect rect)
{
    this->rect.x = rect.x;
    this->rect.y = rect.y;
    this->rect.w = rect.w;
    this->rect.h = rect.h;
}
SDL_Rect* Sprite::get_rect()
{
    return &this->rect;
}
SDL_Texture* Sprite::get_texture(){
    return this->texture;
}
void Sprite::set_texture(SDL_Texture* tex){
    this->texture = tex;
}


Bird::Bird(int x, int y, int width, int height) : Sprite(x, y , width, height)
{
}
void Bird::caer()
{
    if (this->rect.y < (800 - this->rect.h))
    {
        this->rect.y += this->gravity;
    }
    
}