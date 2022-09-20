#ifndef entity
#define entity

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "Collider.h"

// pos,active,simulated,radius

class Entity {
    SDL_Point* pos;
    SDL_Point velocity;
    SDL_Point acceleration;
    // behavior
    
    // collision stuff
    BoxCollider* col;
    bool colliding = false;
    SDL_Point collision_angle;

    public:
        Entity();
        Entity(SDL_Point pos, SDL_Point velocity, SDL_Point accel);
        void update(float dt); // called every frame
        void render();
        void on_collision(SDL_Point angle); // called whenever the entity collides with another
        void on_event(SDL_Event event); // called on event
        
    // getters and setters
        SDL_Point get_pos() {return *this->pos;}
        void set_pos(SDL_Point pos) {*this->pos = pos;}
        SDL_Point get_velocity() {return this->velocity;}
        void set_velocity(SDL_Point velocity) {this->velocity = velocity;}
        BoxCollider* get_collider() {return this->col;}
        bool get_isColliding() {return this->colliding;}
        void set_isColliding(bool b) {this->colliding = b;}
};

#endif