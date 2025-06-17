#ifndef util_h
#define util_h

#include <array>
#include <cstddef>
#include <cstdlib>
#include <chrono>
#include <thread>

constexpr size_t WIDTH = 40;
constexpr size_t HEIGHT = 20;
constexpr int FRAME_SLEEP_TIME = 350;

constexpr size_t initX = WIDTH/2;
constexpr size_t initY = HEIGHT/2;

using Arr2D = std::array<std::array<char, WIDTH>, HEIGHT>;

struct Vec{
    int x {};
    int y {};
};

namespace Dir {
enum Dir {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
};
}

inline constexpr std::array<Vec, 4> dirs {{
    {0, -1}, //UP
    {0, 1}, //DOWN
    {-1, 0}, //LEFT
    {1, 0} //RIGHT
}};

inline void sleep(int x){
    std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

inline void clearConsole()
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

#endif