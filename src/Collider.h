#ifndef collider
#define collider

#include <SDL2/SDL.h>
#include <iostream>
#include "helpers.h"

class Collider {
    protected:
    SDL_Point *pos;
    bool active;
    bool simulated;

    public:
        Collider() {std::cout << "Collider can't be initialized" << std::endl;}
        // overloaded virtual functions need to have the same params
        //virtual SDL_Point check_collision(Collider other) {return {-2,-2};};

        // getters and setters
        SDL_Point* getPos() {return this->pos;}
};
#endif

#ifndef circle_collider
#define circle_collider

class CircleCollider : public Collider{
    protected:
    int radius;
    public:
    CircleCollider(int radius);
    SDL_Point check_collision(CircleCollider other);
    // how do i get box up here?

    int getRadius() {return this->radius;}
};

#endif

#ifndef box_collider
#define box_collider

class BoxCollider : public Collider{
    protected:
    int w;
    int h;
    public:
    BoxCollider(int w,int h);
    SDL_Point check_collision(BoxCollider other);
    SDL_Point check_collision(CircleCollider other);

    int getWidth() {return this->w;}
    int getHeight() {return this->h;}
};

#endif