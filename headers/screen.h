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

    bool isGameOver();
    void setGameOver();

    Screen(Snake& snake_);
private:
    bool gameOver {false};
};
#endif