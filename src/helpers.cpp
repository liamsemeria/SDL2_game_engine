#include "helpers.h"

float dist(SDL_Point p0, SDL_Point p1) {return sqrt( pow(abs(p1.x - p0.x),2) + pow(abs(p1.y - p0.y),2) );}
