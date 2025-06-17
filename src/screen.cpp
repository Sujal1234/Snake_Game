#include "util.h"
#include "snake.h"
#include "screen.h"
#include <iostream>
#include <cstdlib>

Screen::Screen(Snake& snake_)
: snake {snake_}
{}

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

    genFood();
}

void Screen::show() {
    for(size_t row = 0; row < HEIGHT; ++row) {
        for(size_t col = 0; col < WIDTH; ++col) {
            //Print each character of the grid
            std::cout << grid[row][col];
        }
        std::cout << '\n';
    }
}

//Destroy the old food and randomly generate new food;
void Screen::genFood(){
    if(food.x > 0 && food.y > 0){
        char& c = grid[static_cast<size_t>(food.y)][static_cast<size_t>(food.x)];
        if(c == 'O'){
            c = ' ';
        }
    }

    int x {}, y {};

    //Ensure the new position is not the same as the old food position.
    //Also make sure it's not generated on the snake's body.
    do {
        x = static_cast<size_t>(rand()) % (WIDTH-2) + (size_t)1;
        y = static_cast<size_t>(rand()) % (HEIGHT - 2) + (size_t)1;
    } while((x == food.x && y == food.y) ||
            grid[static_cast<size_t>(y)][static_cast<size_t>(x)] == 'A');

    food.x = x;
    food.y = y;
    grid[static_cast<size_t>(food.y)][static_cast<size_t>(food.x)] = 'O';
}