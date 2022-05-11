#ifndef collider
#define collider

#include <SDL2/SDL.h>
#include <iostream>

struct Collider;
struct CircleCollider;
struct BoxCollider;

/*
namespace:
colliders are structs
functions that compare colliders
*/

// circle circle
SDL_Point check_collision(CircleCollider c0, CircleCollider c1);
// circle box
SDL_Point check_collision(BoxCollider c0, CircleCollider c1);
// box box
SDL_Point check_collision(BoxCollider c0, BoxCollider c1);


struct  Collider {
    SDL_Point *pos;
    int n = 1;
    bool active = true;
    bool simulated = true;
};

struct CircleCollider : public Collider{
    int radius;
    CircleCollider() {radius = -1;}
    CircleCollider(SDL_Point *pos, int radius) {
        this->pos = pos;
        this->radius = radius;
    }
};

struct BoxCollider : public Collider{
    int w;
    int h;
};

#endif