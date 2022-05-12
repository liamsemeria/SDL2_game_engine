#include "Entity.h"
#include "Game.h"
#include "helpers.h"

Entity::Entity(SDL_Point pos, SDL_Point velocity, SDL_Point accel) {
    this->pos = new SDL_Point(); 
    *this->pos = pos;
    this->velocity = velocity;
    this->acceleration = accel;
    this->col = new CircleCollider(this->pos,20);
}

void Entity::update(float dt) {
    *this->pos = {int(pos->x + velocity.x*dt), int(pos->y + velocity.y*dt)};
    int x,y;
    SDL_GetMouseState(&x,&y);
    *pos = {x,y};

    this->velocity = {int(velocity.x + acceleration.x*dt), int(velocity.y + acceleration.y*dt)};
    //set_pos({pos.x + velocity.x*, pos.y + velocity.y});
}

// just try dont worry about it (no stakes)
void Entity::on_collision(SDL_Point angle) {
    //Game::get_instance().reset();
    collision_angle = angle;
    velocity = scalar(angle,-1);
    colliding = true;
} // meant to be overloaded