#include "Game.h"
#include "helpers.h"

// public functions

void Game::instantiate(Entity e) {
    this->entities.push_back(e);
}


// constructor
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
}

Game& Game::get_instance() {
    static Game inst;
    return inst;
}

void Game::run() {
    running = true;
    // deltatime
    long time = std::chrono::system_clock::now().time_since_epoch().count();
    long prevtime;
    long dt;
    // collisions
    SDL_Point col_angle;
    //SDL_Point col_angle;
    // TEST
    this->entities.push_back(Entity({700,700},{0,-14},{0,00}));
    this->entities.push_back(Entity({500,500},{0,10},{0,0}));
    while (running)
    {
        // get delta time
        prevtime = time;
        time = std::chrono::system_clock::now().time_since_epoch().count();
        dt = time - prevtime;
        // update entities
        for (int i = 0; i < entities.size(); i++) {
            entities[i].update(float(dt) / 100000 ); // need to convert to micro? seconds here
        }
        
        // check for collisions
        for (int i = 0; i < entities.size(); i++) {
            for (int j = i+1; j < entities.size(); j++) {
                col_angle = check_collision(entities[i].get_collider(), entities[j].get_collider());
                if (col_angle.x != NULL_PT.x && !entities[i].get_isColliding()) {
                    // call on_collision for both entities
                    // be careful when destroying entities here!!!!
                    printf("%d %d \n", col_angle.x, col_angle.y);
                    entities[i].on_collision(col_angle);
                    entities[j].on_collision(scalar(col_angle,-1));
                }
                else if (entities[i].get_isColliding() || entities[j].get_isColliding()) { // should always be equal to each other
                    entities[i].set_isColliding(false);
                    entities[j].set_isColliding(false);
                }
            }
        }
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
                if (event.key.keysym.sym == SDLK_r)
                    this->reset();
                break;
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    // render entities
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    for (Entity e : entities) {
        if (e.get_isColliding()) SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        else SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        draw_circle(renderer,e.get_pos().x,e.get_pos().y, e.get_collider().radius);
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
}

void Game::reset() {
    this->entities.clear();
    this->run();
}

void Game::end() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(texture);
    SDL_Quit();
}