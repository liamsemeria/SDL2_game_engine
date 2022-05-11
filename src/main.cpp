#include <iostream>
#include "Game.h"
#include "helpers.h"

/*
class A {
protected:
int n = 0;
public:
virtual int get() {return n;};
};

class B : public A {
public:
B() {n = 3;}
};

int g(A c) {return c.get();}
Collider col(Collider c) {return c;}
*/

int main() {
        Game::get_instance().run();
        // things to research:
                //Collider b = CircleCollider();
                // type of b is still collider here, but in java it would be circlecollider

                // null sdl_point?
                // sdl_point *,=,== overload

        // things to implement:
                // box colliders
                // interact with engine at runtime with cmd line
                // "collision resolving" after update 
                
}