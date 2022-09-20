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
    SpriteState* s;
    std::vector<const char*> imgpaths;
    // behavior
    
    // collision stuff
    Collider* col;
    bool colliding = false;
    SDL_Point collision_angle;
    // components
    std::vector<Component*> c;

    public:
        Entity();
        Entity(SDL_Point pos, SDL_Point velocity, SDL_Point dim, std::vector<const char*> imgpaths);
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
        void create_collider(SDL_Point dim) {this->col = new Collider(this->pos, dim);}
        Collider* get_collider() {return this->col;}
        bool get_isColliding() {return this->colliding;}
        void set_isColliding(bool b) {this->colliding = b;}
        SDL_Texture* get_image() {if (s!=NULL)return s->sprite(); else return NULL;}
        void set_sprites(SDL_Renderer* renderer, float period); 
};

#endif