#include "util.h"
#include "snake.h"
#include "screen.h"
#include <iostream>

void Screen::initialise(){
    //Fill the grid with spaces
    for (size_t row = 0; row < HEIGHT; ++row) {
        for (size_t col = 0; col < WIDTH; ++col) {
            grid[row][col] = ' ';
        }
    }

    //Draw the border
    for(size_t row = 0; row < HEIGHT; ++row) {
        grid[row][0] = '#';
        grid[row][grid[0].size() - 1] = '#';
    }
    for(size_t col = 0; col < WIDTH; ++col) {
        grid[0][col] = '#';
        grid[grid.size() - 1][col] = '#';
    }

    //Draw the head of the snake
    Vec& head = snake.head();
    grid[static_cast<size_t>(head.y)][static_cast<size_t>(head.x)] = 'A';
}

void Screen::show() {
    for(size_t row = 0; row < HEIGHT; ++row) {
        for(size_t col = 0; col < WIDTH; ++col) {
            std::cout << grid[row][col];
        }
        std::cout << '\n';
    }
}

Screen::Screen(Snake& snake_)
: snake {snake_}
{}