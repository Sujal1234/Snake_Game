#ifndef snake_h
#define snake_h

#include "util.h"
#include <list>

class Snake {
public:
    std::list<Vec> body {}; //Front is the head of the snake
    Vec velocity {1, 0}; //x velocity, y velocity

    Snake(int headX, int headY);
    Vec& head();
    Vec& tail();
    void update(Arr2D& grid);
};
#endif