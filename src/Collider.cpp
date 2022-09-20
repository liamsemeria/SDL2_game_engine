#include "Collider.h"
#include "helpers.h"

Collider::Collider(SDL_Point* pos, SDL_Point dim) {
    this->pos = pos;
    this->dim = dim;
}

SDL_Point check_collision(Collider c0, Collider c1) {
        SDL_Rect r1 = {c1.pos->x,c1.pos->y,c1.dim.x,c1.dim.y};
        SDL_Point tr = {c0.pos->x + c0.dim.x,c0.pos->y};
        SDL_Point br = {c0.pos->x + c1.dim.x,c0.pos->y + c0.dim.y};
        SDL_Point bl = {c0.pos->x,c0.pos->y + c0.dim.y};
        if (SDL_PointInRect(c0.pos,&r1)) return {0,1};
        if (SDL_PointInRect(&tr,&r1)) return {0,1};
        if (SDL_PointInRect(&br,&r1)) return {0,1};
        if (SDL_PointInRect(&bl,&r1)) return {0,1};
    return NULL_PT;
}
