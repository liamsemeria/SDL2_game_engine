#include "Game.h"
// HELPERS
// draws a filled circle
// based off of: https://stackoverflow.com/questions/38334081/howto-draw-circles-arcs-and-vector-graphics-in-sdl
void draw_circle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
   const int32_t diameter = (radius * 2);
   int32_t x = (radius - 1);
   int32_t y = 0;
   int32_t tx = 1;
   int32_t ty = 1;
   int32_t error = (tx - diameter);
   while (x >= y) {
      //  Each of the following renders an octant of the circle
      SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);
      if (error <= 0) {
         ++y;
         error += ty;
         ty += 2;
      }
      if (error > 0) {
         --x;
         tx += 2;
         error += (tx - diameter);
      }
   }
    // added code to fill circle:
    //if (radius == 1) SDL_RenderDrawPoint(renderer, centreX, centreY);
    //else draw_circle(renderer, centreX, centreY, radius-1);
}

Game::Game() {
    // change flags based on wether ot not fullscreen is true
    int flags = 0;
    int dsply = 0; // display number
        
    // initialize the SDL framework
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        // enumerate displays
        int displays = SDL_GetNumVideoDisplays();
        if (displays > 1) dsply = 1; // if we have secondary monitor switch to it
        //if (fullscreen && dsply == 1) flags = SDL_WINDOW_FULLSCREEN; // only set to fullscreen if secondary display

        // get display bounds for all displays
        std::vector< SDL_Rect > displayBounds;
        for( int i = 0; i < displays; i++ ) {
            displayBounds.push_back( SDL_Rect() );
            SDL_GetDisplayBounds( i, &displayBounds.back() );
        }

        // window of dimensions 500 * 500 on secondary monitor
        int x = displayBounds[dsply].x;
        int y = displayBounds[dsply].y;
        int w = displayBounds[dsply].w;
        int h = displayBounds[dsply].h;
        sizex = w;
        sizey = h;
        printf("%d %d \n",sizex,sizey);
        // create a window
        window = SDL_CreateWindow("Game", x, y, w, h, flags);
    }
    // create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    // create texture
    texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STATIC, sizex, sizey);
    // TEST
    this->entities.push_back(Entity({200,200},{0,0}));
}

Game& Game::get_instance() {
    static Game inst;
    return inst;
}

void Game::run() {
    running = true;
    while (running)
    {
        handle_events();
        render();
    }
    end();
}

void Game::handle_events() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    running = false;
                break;
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    // render entities
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    for (Entity e : entities) {
        draw_circle(renderer,e.get_pos().x,e.get_pos().y, 50);
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
}

void Game::end() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(texture);
    SDL_Quit();
}