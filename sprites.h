#ifndef SDL2_H
    #define SDL2_H
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#endif

class Sprite
{
    protected:
        SDL_Rect rect;
        SDL_Texture* texture;
        SDL_Surface* surface;
    public:
        Sprite(int x, int y, int width, int height);
        Sprite(SDL_Rect rect);
        SDL_Rect* get_rect();
        SDL_Texture* get_texture();
        void set_texture(SDL_Texture* tex);

};

class Bird : public Sprite
{
    private:
        const int gravity = 10;
    public:
        Bird(int x, int y, int width, int height);
        void caer();

};