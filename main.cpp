#include <iostream>
#include <vector>

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


void showGrid(std::vector<std::vector<char>>& gameGrid){
    size_t gridHeight = gameGrid.size();
    size_t gridWidth = gameGrid[0].size();
    
    clearConsole();

    for(size_t row = 0; row < gridHeight; ++row) {
        for(size_t col = 0; col < gridWidth; ++col) {
            std::cout << gameGrid[row][col];
        }
        std::cout << '\n';
    }

}

int main() {
    std::vector<std::vector<char>> grid(HEIGHT, std::vector<char>(WIDTH));

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

    showGrid(grid);
    return 0;
}