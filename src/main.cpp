#include <iostream>
#include "Game.h"
#include "helpers.h"

//CircleCollider* col(CircleCollider* c) {return c;}

int main() {
        std::vector<const char*> paths = {"assets/a0.png","assets/a1.png"};
        Entity* e = new Entity({500,500},{20,0},{200,200},paths);
        e->create_collider({200,200});
        Entity* e1 = new Entity({1200,500},{00,0},{200,200},paths);
        e1->create_collider({200,200});
        Game::get_instance().instantiate(e);
        Game::get_instance().instantiate(e1);

        Game::get_instance().run();

        /* things to implement:
                collider offset
                sprite states
        */
                
}