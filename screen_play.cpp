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

    SDL_Surface* surTopTube = IMG_Load("resources/top_tube.png");
    if (surTopTube == nullptr)
    {
        cout << "IMG_Load surTopTube Error" << SDL_GetError() << endl;
        return;
    }
    SDL_Texture* texTopTube = SDL_CreateTextureFromSurface(ren, surTopTube);
    SDL_FreeSurface(surTopTube);
    if (texTopTube == nullptr)
    {
        cout << "Texture texTopTube Error" << SDL_GetError() << endl;
        return;
    }
    SDL_Surface* surBottomTube = IMG_Load("resources/bottom_tube.png");
    if (surBottomTube == nullptr)
    {
        cout << "IMG_Load surBottomTube Error" << SDL_GetError() << endl;
        return;
    }
    SDL_Texture* texBottomTube = SDL_CreateTextureFromSurface(ren, surBottomTube);
    SDL_FreeSurface(surBottomTube);
    if (texTopTube == nullptr)
    {
        cout << "Texture texTopTube Error" << SDL_GetError() << endl;
        return;
    }

    // Creando Sprites
    sprBackground = new Sprite(0, 0, this->width, this->height);
    sprGround1 = new Sprite(0, this->height - 80 - GROUND_OFFSET, 240, 80);
    sprGround2 = new Sprite(240, this->height - 80 - GROUND_OFFSET, 240, 80);
    sprBackground->set_texture(texBackground);
    sprGround1->set_texture(texGround);
    sprGround2->set_texture(texGround);

    // Construimos el arreglo de Tubes
    for (int i = 0; i < TUBE_COUNT; i++)
    {
        Tube* tube = new Tube(texTopTube, texBottomTube, i * (TUBE_WIDTH + TUBE_SPACING), this->height);
        this->tubes.push_back(*tube);
    }
}
void ScreenPlay::handleInput(SDL_Event *event)
{
        
}
void ScreenPlay::update(Uint32 dt)
{
    if (sprGround1->get_rect()->x <= -240){
        sprGround1->get_rect()->x = 240;
    }
    if (sprGround2->get_rect()->x <= -240){
        sprGround2->get_rect()->x = 240;
    }
    sprGround1->get_rect()->x -= GROUND_VELOCITY;
    sprGround2->get_rect()->x -= GROUND_VELOCITY;

    // Reposicionamos los tubos segun la velocidad del juego
    for (int i = 0; i < TUBE_COUNT; i++)
    {
        Tube tube = this->tubes[i];
        tube.reposition(tube.get_bottom_tube_rect()->x - GROUND_VELOCITY);  // TODO: A mejorar
        reposition(&tube);
    }

    
}
void ScreenPlay::render()
{
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, this->sprBackground->get_texture(), NULL, this->sprBackground->get_rect());
    SDL_RenderCopy(ren, this->sprGround1->get_texture(), NULL, this->sprGround1->get_rect());
    SDL_RenderCopy(ren, this->sprGround2->get_texture(), NULL, this->sprGround2->get_rect());

    //Renderizamos tubes
    for (int i = 0; i < TUBE_COUNT; i++)
    {
        Tube tube = this->tubes[i];
        SDL_RenderCopy(ren, tube.get_texture_top_tube(), NULL, tube.get_top_tube_rect());
        SDL_RenderCopy(ren, tube.get_texture_bottom_tube(), NULL, tube.get_bottom_tube_rect());
    } 

    SDL_RenderPresent(ren);
}
void ScreenPlay::dispose()
{
    
}

void ScreenPlay::reposition(Tube* tube)
{
    if (tube->get_x() < -TUBE_WIDTH)
    {
        tube->reposition((3 * (TUBE_WIDTH + TUBE_SPACING)) + TUBE_SPACING );
    }
}