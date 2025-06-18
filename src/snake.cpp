#include "snake.h"
#include "screen.h"
#include "util.h"
#include <cstddef>
#include <cassert>

Snake::Snake(int headX, int headY) {
    body.push_back({headX, headY});
}
    
Vec& Snake::head(){
    return body.front();
}
    
Vec& Snake::tail(){
    return body.back();
}

void Snake::setDir(const Vec& direction){
    velocity = direction;
}

void Snake::move(Screen& screen){
    Arr2D& grid = screen.grid;
    //Assuming the grid currently contains snake's body
    Vec bodyHead = head();
    Vec bodyTail = tail();
    
    assert(grid.at(static_cast<size_t>(bodyHead.y)).at(static_cast<size_t>(bodyHead.x)) == 'A');

    int newX = bodyHead.x + velocity.x;
    int newY = bodyHead.y + velocity.y;

    if(grid[static_cast<size_t>(newY)][static_cast<size_t>(newX)] == 'A'){
        if(newX != bodyTail.x || newY != bodyTail.y){
            screen.setGameOver();
            return;
        }
    }

    if(static_cast<size_t>(newY+1) >= grid.size() || newY < 1 || newX < 1 || static_cast<size_t>(newX+1) >= grid[0].size()){
        //TODO: Either game over or teleportation
        return;
    }

    Vec newHead {newX, newY};

    //Remove tail first, because the new head position might be the old tail position
    body.pop_back();
    grid[static_cast<size_t>(bodyTail.y)][static_cast<size_t>(bodyTail.x)] = ' ';

    body.push_front(newHead);
    grid[static_cast<size_t>(newY)][static_cast<size_t>(newX)] = 'A';
}

bool Snake::eat(Screen& screen){
    Arr2D& grid = screen.grid;
    Vec bodyHead = head();
    assert(grid.at(static_cast<size_t>(bodyHead.y)).at(static_cast<size_t>(bodyHead.x)) == 'A');

    int newX = bodyHead.x + velocity.x;
    int newY = bodyHead.y + velocity.y;

    if(newX == screen.food.x && newY == screen.food.y){
        Vec newHead {newX, newY};
        body.push_front(newHead);

        grid[static_cast<size_t>(newY)][static_cast<size_t>(newX)] = 'A';
        screen.genFood();
        
        return true;
    }
    else{
        return false;
    }
}

void Snake::update(Screen& screen) {
    if(!eat(screen)){
        //TODO: Disallow 180 deg turning
        move(screen);
    }
}