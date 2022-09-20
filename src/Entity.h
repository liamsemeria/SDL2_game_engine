#ifndef entity
#define entity

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "Collider.h"
#include "Component.h"

// pos,active,simulated,radius

class Entity {
    SDL_Point* pos;
    SDL_Point velocity;
    SDL_Point acceleration;
    SDL_Point dim;
    SDL_Texture* image = NULL;
    const char* imgpath;
    // behavior
    
    // collision stuff
    Collider* col;
    bool colliding = false;
    SDL_Point collision_angle;
    // components
    std::vector<Component*> c;

    public:
        Entity();
        Entity(SDL_Point pos, SDL_Point velocity, SDL_Point dim, const char* imgpath);
        ~Entity();
        void update(float dt); // called every frame
        void render();
        void on_collision(SDL_Point angle); // called whenever the entity collides with another
        void on_event(SDL_Event event); // called on event
        void add_component(Component* c);
        
    // getters and setters
        SDL_Point get_pos() {return *this->pos;}
        void set_pos(SDL_Point pos) {*this->pos = pos;}
        SDL_Point get_velocity() {return this->velocity;}
        void set_velocity(SDL_Point velocity) {this->velocity = velocity;}
        SDL_Point get_dim() {return this->dim;}
        void set_dim(SDL_Point dim) {this->dim = dim;}
        Collider* get_collider() {return this->col;}
        bool get_isColliding() {return this->colliding;}
        void set_isColliding(bool b) {this->colliding = b;}
        SDL_Texture* get_image() {return this->image;}
        void set_image(SDL_Renderer* renderer); 
};

#endif