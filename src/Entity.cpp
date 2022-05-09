#include "Entity.h"

Entity::Entity(SDL_Point pos, SDL_Point velocity) {
    this->pos = pos; this->velocity = velocity;
}
void Entity::update() {} //  meant to be overloaded
void Entity::on_collision() {} // meant to be overloaded