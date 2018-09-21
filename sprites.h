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

class Tube
{
    private:
        SDL_Texture* texTopTube;
        SDL_Texture* texBottomTube;
        int x;
        SDL_Rect* rectTopTube;
        SDL_Rect* rectBottomTube;
        const int TUBE_WIDTH = 26;
        const int TUBE_HEIGHT = 160;
    public:
        Tube(SDL_Texture* texTopTube, SDL_Texture* texBottomTube, int x, int screen_height);
        void reposition(int x);
        bool collision(SDL_Rect* rect);
        SDL_Rect* get_bottom_tube_rect();
        SDL_Rect* get_top_tube_rect();
        SDL_Texture* get_texture_top_tube();
        SDL_Texture* get_texture_bottom_tube();
        int get_x();
};