#include <SDL2/SDL.h>

class Collider {
    SDL_Point pos;
    public:
    Collider(SDL_Point pos) {this->pos = pos;}
    private:
    bool check_two_colliders(Collider c0, Collider c1);
};

class CircleCollider : Collider {
    int radius;
    public:
    CircleCollider(SDL_Point pos, int radius);
    bool check_collision(Collider c);
    // getters
    int get_rad() {return this->radius;}
};