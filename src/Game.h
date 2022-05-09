#ifndef game
#define game

#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <chrono>
// homemade
#include "Entity.h"

/* 
Game is a singletom
    c++ pattern: https://stackoverflow.com/questions/270947/can-any-one-provide-me-a-sample-of-singleton-in-c/271104#271104
    this implementation may lead to seg faults down the line if i use heap memory in Game()
*/
class Game {
    // SDL, rendering
    bool running;
    int sizex,sizey; // size of rendered game screen
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    // engine
    std::vector<Entity> entities;
    float time_passed;

    public:
        static Game& get_instance();
        void run();
    private:
        Game();
        Game(Game const&);
        void operator=(Game const &);
        void end();
        void render();
        void handle_events();
};
#endif