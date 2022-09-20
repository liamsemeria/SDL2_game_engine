#include "helpers.h"


// Calculations

// to vector
SDL_Point to_vector(SDL_Point p0, SDL_Point p1) {
    return {p1.x - p0.x,p1.y - p0.y};
}
float magnitude(SDL_Point v) {
    return SDL_sqrtf(float(v.x*v.x + v.y*v.y));
    //return SDL_sqrtf(v.x*v.x + v.y*v.y);
}
SDL_Point scalar(SDL_Point p,int s) {
    return {s * p.x, s * p.y};
}

// Rendering

void draw_circle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius)
    {
    const int32_t diameter = (radius * 2);
    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);
    while (x >= y) {
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);
        if (error <= 0) {
            ++y;
            error += ty;
            ty += 2;
        }
        if (error > 0) {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
        // added code to fill circle:
        //if (radius == 1) SDL_RenderDrawPoint(renderer, centreX, centreY);
        //else draw_circle(renderer, centreX, centreY, radius-1);
    }

SDL_Texture* load_img(const char* filepath, SDL_Renderer* renderer) {
    SDL_Surface* s = IMG_Load(filepath);
    if (s==NULL) {printf("couldnt load image at %s \n",filepath); SDL_FreeSurface(s); return NULL;}
    SDL_Texture* t = SDL_CreateTextureFromSurface(renderer, s);
    SDL_FreeSurface(s);
    return t;
}