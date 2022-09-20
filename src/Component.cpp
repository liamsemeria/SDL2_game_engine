#include "Component.h"
#include "helpers.h"

// SPRITES
SpriteState::SpriteState(SDL_Renderer* renderer, std::vector<const char*> paths, float period) {
    this->period = period;
    for (int i = 0; i < paths.size(); i++) {
        this->img_states.push_back(load_img(paths[i],renderer));
    }
}

void SpriteState::update(float dt) {
    this->t+= dt;
    if (t > period) {
        t = 0;
        state++;
        if (state==img_states.size()) state = 0;
    }
}

SDL_Texture* SpriteState::sprite() {
    return img_states[state];
}