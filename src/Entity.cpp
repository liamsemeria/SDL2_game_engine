#include "Entity.h"
#include "Game.h"
#include "helpers.h"

Entity::Entity(SDL_Point pos, SDL_Point velocity, SDL_Point dim, std::vector<const char*> imgpaths) {
    this->pos = new SDL_Point(); 
    *this->pos = pos;
    this->velocity = velocity;
    this->acceleration = {0,0};
    this->imgpaths = imgpaths;
    this->dim = dim;
    this->col = NULL;
    this->s = NULL;
}

Entity::~Entity() {
    SDL_DestroyTexture(this->image);
}

void Entity::update(float dt) {
    *this->pos = {int(pos->x + velocity.x*dt), int(pos->y + velocity.y*dt)};
    //int x,y;
    //SDL_GetMouseState(&x,&y);
    //*pos = {x,y};
    this->velocity = {int(velocity.x + acceleration.x*dt), int(velocity.y + acceleration.y*dt)};
    if (s!=NULL) s->update(dt);
}

// just try dont worry about it (no stakes)
void Entity::on_collision(SDL_Point angle) {
    //Game::get_instance().reset();
    collision_angle = angle;
    velocity = scalar(angle,-1);
    colliding = true;
} // meant to be overloaded

void Entity::on_event(SDL_Event event) {
    //if (event.type == SDL_MOUSEBUTTONDOWN) {printf("balls");}
}

void Entity::set_sprites(SDL_Renderer* renderer, float period) {
    this->s = new SpriteState(renderer,this->imgpaths,period);
    return;
}

void Entity::add_component(Component* c) {
    this->c.push_back(c);
    printf("adding component: %s \n",typeid(c).name());
}