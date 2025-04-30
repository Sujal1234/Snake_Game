#include "snake.h"
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

void Snake::update(Arr2D& grid) {
    //Assuming the grid currently contains snake's body
    Vec tail = body.back();
    assert(grid.at(static_cast<size_t>(tail.y)).at(static_cast<size_t>(tail.x)) == 'A');

    int newX = tail.x + velocity.x;
    int newY = tail.y + velocity.y;

    if(static_cast<size_t>(newY+1) >= grid.size() || newY < 1 || newX < 1 || static_cast<size_t>(newX+1) >= grid[0].size()){
        //TODO: Either game over or teleportation
        return;
    }

    Vec newHead {newX, newY};
    body.push_front(newHead);
    body.pop_back();

    grid[static_cast<size_t>(newY)][static_cast<size_t>(newX)] = 'A';
    grid[static_cast<size_t>(tail.y)][static_cast<size_t>(tail.x)] = ' ';        
}