#include <iostream>
#include <array>
// #include <vector>
#include <list>
#include <chrono>
#include <thread>
#include <cassert>

#include "snake.h"
#include "screen.h"
#include "util.h"

Vec::Vec(int xPos, int yPos)
    : x {xPos}
    , y {yPos}
    {}


void loop(Screen& screen);
void sleep(int x);


void loop(Screen& screen){
    // clearConsole();
    screen.show();
    screen.snake.update(screen.grid);
}

void sleep(int x){
    std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

int main() {
    Snake snake(WIDTH/2, HEIGHT/2);

    Screen screen(snake);
    screen.initialise();
    screen.show();
    
    while(true){
        loop(screen);
        sleep(750);
    }
    return 0;
}