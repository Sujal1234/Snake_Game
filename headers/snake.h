#ifndef snake_h
#define snake_h

#include "util.h"
#include "screen.h"
#include <list>
class Screen;

class Snake {
public:
    Vec& head();
    Vec& tail();

    Snake(int headX, int headY);
    void setDir(const Vec& direction);
    // void grow();
    void update(Screen& screen);

private:
    std::list<Vec> body {}; //Front is the head of the snake
    Vec velocity {1, 0}; //x velocity, y velocity

    void move(Screen& screen);
    bool eat(Screen& screen);
};
#endif