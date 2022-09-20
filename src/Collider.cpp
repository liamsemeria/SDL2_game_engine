#include "Collider.h"
#include "helpers.h"

// circle circle
SDL_Point check_collision(CircleCollider c0, CircleCollider c1) {
    SDL_Point v = to_vector(*c0.pos,*c1.pos);
    float m = magnitude(v);
        if (m <= c0.dim.x + c1.dim.y) {
            // avoid dividing by zero
            if (m == 0) return {0,0};
            return {v.x / (int) m, v.y / (int) m};
        }
        return NULL_PT;
}

SDL_Point check_collision(BoxCollider c0, BoxCollider c1) {
    if (c0.type=="box") { 
        SDL_Rect r1 = {c1.pos->x,c1.pos->y,c1.dim.x,c1.dim.y};
        SDL_Point tr = {c0.pos->x + c0.dim.x,c0.pos->y};
        SDL_Point br = {c0.pos->x + c1.dim.x,c0.pos->y + c0.dim.y};
        SDL_Point bl = {c0.pos->x,c0.pos->y + c0.dim.y};
        if (SDL_PointInRect(c0.pos,&r1)) return {0,1};
        if (SDL_PointInRect(&tr,&r1)) return {0,1};
        if (SDL_PointInRect(&br,&r1)) return {0,1};
        if (SDL_PointInRect(&bl,&r1)) return {0,1};
    }
    return NULL_PT;
}
