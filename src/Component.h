#ifndef component
#define component
// components encapsulate any optional feature for entities like colliders or images

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

class Component {
    public:
    bool active;
    Component() {active = false;};
    virtual ~Component() {}
};

class SpriteState : public Component {
    int state = 0;
    float period;
    float t = 0;
    std::vector<SDL_Texture*> img_states;
    public:
    SpriteState(SDL_Renderer* renderer, std::vector<const char*> paths, float period);
    void update(float dt);
    SDL_Texture* sprite();
};

#endif