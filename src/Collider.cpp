#include "Collider.h"
#include "helpers.h"

// circle circle
SDL_Point check_collision(Collider c0, Collider c1) {
    //return check_collision((CircleCollider) c0,(CircleCollider) c1);
    if (c0.type=="circle") {
        SDL_Point v = to_vector(*c0.pos,*c1.pos);
        float m = magnitude(v);
        if (m <= c0.dim.x + c1.dim.y) {
            // avoid dividing by zero
            if (m == 0) return {0,0};
            return {v.x / (int) m, v.y / (int) m};
        }
    }
    return NULL_PT;
} 
