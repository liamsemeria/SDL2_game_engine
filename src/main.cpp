#include <iostream>
#include "Game.h"
#include "helpers.h"

CircleCollider* col(CircleCollider* c) {return c;}

int main() {
        Game::get_instance().run();
        // things to research:
                // null sdl_point?
                // sdl_point *,=,== overload

        // things to implement:
                // box colliders
                // interact with engine at runtime with cmd line
                // "collision resolving" after update 
                
}