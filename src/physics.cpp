#include <SDL2/SDL.h>

struct Collider {
    SDL_Point pos;
    bool active;
    bool simulated; // wether or not the collider is simulated, if not it works as a trigger
};
struct CircleCollider : Collider {
    int radius;
};

// helpers
static float dist(SDL_Point p0, SDL_Point p1) {return sqrt( pow(abs(p1.x - p0.x),2) + pow(abs(p1.y - p0.y),2) );}

// the Collider class houses a function that checks for collisions, and its children call that function on themselves
static SDL_Point check_collision(CircleCollider c0, CircleCollider c1) {
    // circle, circle
    if (dist(c0.pos,c1.pos) < c0.radius + c1.radius) {
        return {c1.pos.x - c0.pos.x, c1.pos.y - c0.pos.y};
    }
    return {-1,-1};
}