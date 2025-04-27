#include <iostream>
#include <array>
// #include <vector>
#include <list>
#include <chrono>
#include <thread>
#include <cassert>
#include <csignal>
#include "econio.h" //To handle key presses

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
    clearConsole();
    screen.show();
    screen.snake.update(screen.grid);
}

void sleep(int x){
    std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

volatile std::sig_atomic_t gSignalStatus {-1};
extern "C" void signalHandler(int signal){
    gSignalStatus = signal;
}

int main() {
    std::signal(SIGINT, signalHandler);
    econio_rawmode();

    Snake snake(WIDTH/2, HEIGHT/2);

    Screen screen(snake);
    screen.initialise();
    screen.show();
    
    while(gSignalStatus == -1){
        loop(screen);
        sleep(750);
    }

    econio_normalmode();
    std::cout << "Game over.\n";
    return 0;
}