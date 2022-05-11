#ifndef entity
#define entity

#include <SDL2/SDL.h>
#include <vector>
#include "Collider.h"

// pos,active,simulated,radius

class Entity {
    SDL_Point* pos;
    SDL_Point velocity;
    SDL_Point acceleration;
    char* tag;
    // collision stuff
    CircleCollider col;
    bool colliding = false;
    SDL_Point collision_angle;

    public:
        Entity() {}
        Entity(SDL_Point pos, SDL_Point velocity, SDL_Point accel);
        void update(float dt); // this function is called every frame, and is meant to be overloaded
        void on_collision(SDL_Point angle); // this function is called whenever the entity collides with another
        
    // getters and setters
        SDL_Point get_pos() {return *this->pos;}
        void set_pos(SDL_Point pos) {*this->pos = pos;}
        SDL_Point get_velocity() {return this->velocity;}
        void set_velocity(SDL_Point velocity) {this->velocity = velocity;}
        CircleCollider get_collider() {return this->col;}
        bool get_isColliding() {return this->colliding;}
        void set_isColliding(bool b) {this->colliding = b;}
};

#endif