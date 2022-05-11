#ifndef helpers
#define helpers

#include <SDL2/SDL.h>
#include <iostream>

    // Calculations
    // SUS CODE SUS CODE SUS CODE SUS CODE
    //#define NULL_PT {100000,1000000};
    const SDL_Point NULL_PT = {100000,1000000};
    // vectors
    SDL_Point to_vector(SDL_Point p0, SDL_Point p1);
    // magnitude of vector
    float magnitude(SDL_Point v);
    // point times scalar
    SDL_Point scalar(SDL_Point p,int s);

    // Rendering

    // draws a filled circle
    // based off of: https://stackoverflow.com/questions/38334081/howto-draw-circles-arcs-and-vector-graphics-in-sdl
    void draw_circle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius);

#endif