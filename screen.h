#ifndef screen_h
#define screen_h

#include "util.h"
#include "screen.h"
class Screen {
public:
    Arr2D grid {};
    Snake& snake;

    void initialise();    
    void show();

    Screen(Snake& snake_);
};
#endif