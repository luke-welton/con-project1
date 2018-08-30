#ifndef PROJECT_1_GAME_H
#define PROJECT_1_GAME_H

#include "Character.h"
#include "Difficulty.h"

class Game {
private:
    int time, mapSize;
    Character* player;
    Difficulty* chosenDifficulty;
public:
    Game(Difficulty *diffIn, string nameIn = "Corrin");

    void run();

    void move();
    void read();
    void work();
    void play();
    void viewStats();
    void giveUp();

    bool isAtEnd();
    bool gameOver();
};

#endif //PROJECT_1_GAME_H