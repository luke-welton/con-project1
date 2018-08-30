/**
 * This is the driver for the whole program, the one that starts it all!
 * As you can see, this file doesn't really do a whole lot on its own.
 *
 * Creator: Luke Welton (law0047@auburn.edu)
 * Filename: Project1.cpp
 *
 * To compile the entire project, you need to enter:
 *
 *  g++ -o Project1.exe Project1.cpp Character.cpp Difficulty.cpp Encounter.cpp Game.cpp HighScore.cpp Menu.cpp
 *      ScoreList.cpp System.cpp
 *
 * and hit enter. From there, enter
 *
 *  ./Project1.exe
 *
 * and the program will run!
 *
 * For this file specifically, I did not use any outside help.
 */

#include "System.h"

int main() {
    System boot;
    boot.displayIntro();

    bool exit = false;
    while (!exit) {
        exit = boot.displayMainMenu();
    }
    return 0;
}