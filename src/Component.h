#ifndef component
#define component
// components encapsulate any optional feature for entities like colliders or images

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Component {
    public:
    bool active;
    Component() {active = false;};
    virtual ~Component() {}
    //virtual void set() {};
};

class Sprite : public Component {
    SDL_Texture* img;
    public:
    Sprite();
    void set();
};

#endif