#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

void clearConsole()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}

constexpr size_t WIDTH = 40;
constexpr size_t HEIGHT = 20;

using Arr2D = std::vector<std::vector<char>>;

void showGrid(Arr2D& gameGrid);
void loop(Arr2D& grid);
void sleep(int x);


void showGrid(Arr2D& grid){
    size_t gridHeight = grid.size();
    size_t gridWidth = grid[0].size();
    
    clearConsole();

    for(size_t row = 0; row < gridHeight; ++row) {
        for(size_t col = 0; col < gridWidth; ++col) {
            std::cout << grid[row][col];
        }
        std::cout << '\n';
    }

}

void loop(Arr2D& grid){
    showGrid(grid);
}

void sleep(int x){
    std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

int main() {
    Arr2D grid(HEIGHT, std::vector<char>(WIDTH));

    for (size_t row = 0; row < HEIGHT; ++row) {
        for (size_t col = 0; col < WIDTH; ++col) {
            grid[row][col] = ' ';
        }
    }

    // Draw the border
    for(size_t row = 0; row < HEIGHT; ++row) {
        grid[row][0] = '#';
        grid[row][WIDTH - 1] = '#';
    }
    for(size_t col = 0; col < WIDTH; ++col) {
        grid[0][col] = '#';
        grid[HEIGHT - 1][col] = '#';
    }

    while(true){
        showGrid(grid);
        sleep(2000);
    }
    return 0;
}