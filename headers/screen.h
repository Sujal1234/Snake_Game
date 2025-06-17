#ifndef screen_h
#define screen_h

#include "util.h"
#include "snake.h"
class Snake; 

class Screen {
public:
    Arr2D grid {};
    Snake& snake;
    Vec food {-1, -1};

    void initialise();    
    void show();
    void genFood();

    Screen(Snake& snake_);
};
#endif