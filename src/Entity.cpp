#include "Entity.h"
#include "Game.h"
#include "helpers.h"

Entity::Entity(SDL_Point pos, SDL_Point velocity, SDL_Point dim, const char* imgpath) {
    this->pos = new SDL_Point(); 
    *this->pos = pos;
    this->velocity = velocity;
    this->acceleration = {0,0};
    this->imgpath = imgpath;
    this->dim = dim;
    this->col = new Collider(this->pos,dim);
    this->c.push_back(new Sprite());
    this->c.push_back(new Collider(this->pos,dim));
}

Entity::~Entity() {
    SDL_DestroyTexture(this->image);
}

void Entity::update(float dt) {
    *this->pos = {int(pos->x + velocity.x*dt), int(pos->y + velocity.y*dt)};
    //int x,y;
    //SDL_GetMouseState(&x,&y);
    //*pos = {x,y};
    this->velocity = {int(velocity.x + acceleration.x*dt), int(velocity.y + acceleration.y*dt)};
    //set_pos({pos.x + velocity.x*, pos.y + velocity.y});
}

// just try dont worry about it (no stakes)
void Entity::on_collision(SDL_Point angle) {
    //Game::get_instance().reset();
    collision_angle = angle;
    velocity = scalar(angle,-1);
    colliding = true;
} // meant to be overloaded

void Entity::on_event(SDL_Event event) {
    //if (event.type == SDL_MOUSEBUTTONDOWN) {printf("balls");}
}

void Entity::set_image(SDL_Renderer* renderer) {
    SDL_Surface* s = IMG_Load(this->imgpath);
    if (s==NULL) {printf("couldnt load image at %s \n",this->imgpath); return;}
    this->image = SDL_CreateTextureFromSurface(renderer, s);
    assert(this->image!=NULL);
    SDL_FreeSurface(s);
}

void Entity::add_component(Component* c) {
    this->c.push_back(c);
    printf("adding component: %s \n",typeid(c).name());
}