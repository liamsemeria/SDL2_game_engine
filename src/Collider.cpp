#include "Collider.h"

CircleCollider::CircleCollider(int radius) {
    this->radius = radius;
}

SDL_Point CircleCollider::check_collision(CircleCollider other) {
    SDL_Point* opos = other.getPos();
    if (dist(*pos,*opos) < radius + other.getRadius()) {return {opos->x - pos->x, opos->y - pos->y};}
    return {-1,-1};
}