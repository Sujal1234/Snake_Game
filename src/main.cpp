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

void loop(Screen& screen);
void gameOver();
void sleep(int x);

void gameOver(){
    econio_normalmode();
    std::cout << "Game over.\n";
    std::exit(0);
}

void loop(Screen& screen){
    clearConsole();

    if(econio_kbhit()){
        switch(econio_getch()) {
            case KEY_UP:
                screen.snake.setDir(dirs[Dir::UP]);
                break;
            case KEY_DOWN:
                screen.snake.setDir(dirs[Dir::DOWN]);
                break;
            case KEY_LEFT:
                screen.snake.setDir(dirs[Dir::LEFT]);
                break;
            case KEY_RIGHT:
                screen.snake.setDir(dirs[Dir::RIGHT]);
                break;
            default:
                break;
        }
    }

    screen.snake.update(screen.grid);
    screen.show();
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

    gameOver();
    return 0;
}