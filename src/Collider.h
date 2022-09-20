#ifndef collider
#define collider

#include <SDL2/SDL.h>
#include "Component.h"

/*
REVISE
namespace:
colliders are structs
functions that compare colliders
*/

class Collider : public Component {
    public:
    SDL_Point *pos;
    bool active = true;
    bool simulated = true;
    SDL_Point dim = {-1,-1};
    Collider(SDL_Point* pos, SDL_Point dim);
    void set();
};

//SDL_Point check_collision(CircleCollider c0, CircleCollider c1);
SDL_Point check_collision(Collider c0, Collider c1);
/*
struct  Collider {
    SDL_Point *pos;
    bool active = true;
    bool simulated = true;
    SDL_Point dim = {-1,-1};
    std::string type = "abstract";
};

struct CircleCollider : public Collider{
    int radius;
    CircleCollider() {}
    CircleCollider(SDL_Point *pos, int radius) {
        this->pos = pos;
        this->radius = radius;
        this->dim = {radius,radius};
        this->type = "circle";
    }
};

struct BoxCollider : public Collider{
    BoxCollider() {}
    BoxCollider(SDL_Point* pos, int width, int height) {
        this->pos = pos;
        this->dim = {width,height};
        this->type = "box";

    }
};
*/
#endif