#include "Collider.h"
#include "helpers.h"

// circle circle
SDL_Point check(Collider c0, Collider c1) {
    //return check_collision((CircleCollider) c0,(CircleCollider) c1);
    return {0,0};
} 

SDL_Point check_collision(CircleCollider c0, CircleCollider c1) {
    SDL_Point v = to_vector(*c0.pos,*c1.pos);
    float m = magnitude(v);
    if (m <= c0.radius + c1.radius) {
        // avoid dividing by zero
        if (m == 0) return {0,0};
        return {v.x / (int) m, v.y / (int) m};
    }
    return NULL_PT;
}
// circle box
SDL_Point check_collision(BoxCollider c0, CircleCollider c1) {

    return NULL_PT;
}
// box box
SDL_Point check_collision(BoxCollider c0, BoxCollider c1) {

    return NULL_PT;
}
