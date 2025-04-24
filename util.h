#ifndef util_h
#define util_h
#include <array>
#include <cstddef>
#include <cstdlib>


constexpr size_t WIDTH = 40;
constexpr size_t HEIGHT = 20;

constexpr size_t initX = WIDTH/2;
constexpr size_t initY = HEIGHT/2;

using Arr2D = std::array<std::array<char, WIDTH>, HEIGHT>;

typedef struct Vec {
    public:
        int x {};
        int y {};
    
        Vec(int xPos, int yPos);
    } Vec;

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