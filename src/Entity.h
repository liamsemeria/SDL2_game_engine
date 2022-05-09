#ifndef entity
#define entity

#include <SDL2/SDL.h>
#include <vector>
#include "Collider.h"

// pos,active,simulated,radius

class Entity {
    SDL_Point pos;
    SDL_Point velocity;
    SDL_Point acceleration;
    Collider col;

    public:
        Entity(SDL_Point pos, SDL_Point velocity);
        void update(float dt); // this function is called every frame, and is meant to be overloaded
        void on_collision(); // this function is called whenever the entity collides with another
        
    // getters and setters
        SDL_Point get_pos() {return this->pos;}
        void set_pos(SDL_Point pos) {this->pos = pos;}
        SDL_Point get_velocity() {return this->velocity;}
        void set_velocity(SDL_Point velocity) {this->velocity = velocity;}
        Collider get_collider() {return col;}
};

#endif