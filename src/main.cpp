#include <iostream>
#include "Game.h"
#include "helpers.h"

//CircleCollider* col(CircleCollider* c) {return c;}

int main() {
        Entity* e = new Entity({500,500},{10,0},{50,50},"assets/a0.png");
        Entity* e1 = new Entity({800,500},{00,0},{50,50},"assets/img.png");
        Game::get_instance().instantiate(e);
        Game::get_instance().instantiate(e1);

        Game::get_instance().run();
        // things to research:
                // null sdl_point?
                // sdl_point *,=,== overload

        // things to implement:
                // box colliders
                // interact with engine at runtime with cmd line
                // "collision resolving" after update 
                
}