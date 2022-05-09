#include "Entity.h"

Entity::Entity(SDL_Point pos, SDL_Point velocity) {
    this->pos = pos; this->velocity = velocity;
    this->acceleration = {0,0};
    //this->col = {this->pos,true,true,20};
}

void Entity::update(float dt) {
    this->velocity = {int(velocity.x + acceleration.x*dt), int(velocity.y + acceleration.y*dt)};
    this->pos = {int(pos.x + velocity.x*dt), int(pos.y + velocity.y*dt)};
    //set_pos({pos.x + velocity.x*, pos.y + velocity.y});
}

void Entity::on_collision() {} // meant to be overloaded