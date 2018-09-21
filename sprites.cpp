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
SDL_Rect *Sprite::get_rect()
{
    return &this->rect;
}
SDL_Texture *Sprite::get_texture()
{
    return this->texture;
}
void Sprite::set_texture(SDL_Texture *tex)
{
    this->texture = tex;
}

Bird::Bird(int x, int y, int width, int height) : Sprite(x, y, width, height)
{
}
void Bird::caer()
{
    if (this->rect.y < (800 - this->rect.h))
    {
        this->rect.y += this->gravity;
    }
}

// Tube implementation
Tube::Tube(SDL_Texture *texTopTube, SDL_Texture *texBottomTube, int x, int screen_height)
{
    this->texTopTube = texTopTube;
    this->texBottomTube = texBottomTube;
    this->x = x;

    this->rectBottomTube = new SDL_Rect();
    this->rectBottomTube->x = x;
    this->rectBottomTube->y = screen_height - TUBE_HEIGHT; // Debe ser random
    this->rectBottomTube->w = TUBE_WIDTH;
    this->rectBottomTube->h = TUBE_HEIGHT; // Debe ser random

    this->rectTopTube = new SDL_Rect();
    this->rectTopTube->x = x;
    this->rectTopTube->y = 0;
    this->rectTopTube->w = TUBE_WIDTH;
    this->rectTopTube->h = TUBE_HEIGHT; // Debe ser random
}
void Tube::reposition(int new_x)
{
    this->x = new_x;
    this->rectBottomTube->x = new_x;
    this->rectTopTube->x = new_x;
}
bool Tube::collision(SDL_Rect *rect)
{
    return (SDL_HasIntersection(rect, rectBottomTube) == SDL_TRUE) ||
           (SDL_HasIntersection(rect, rectTopTube) == SDL_TRUE);
}

SDL_Rect *Tube::get_bottom_tube_rect()
{
    return this->rectBottomTube;
}
SDL_Rect *Tube::get_top_tube_rect()
{
    return this->rectTopTube;
}
SDL_Texture *Tube::get_texture_top_tube()
{
    return this->texTopTube;
}
SDL_Texture *Tube::get_texture_bottom_tube()
{
    return this->texBottomTube;
}
int Tube::get_x()
{
    return this->x;
}