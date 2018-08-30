#ifndef PROJECT_1_CHARACTER_H
#define PROJECT_1_CHARACTER_H

#include "Difficulty.h"
using namespace std;

class Character {
private:
    int money, intel, happy, position;
    string name;
public:
    Character(int m, int i, int h, string nameIn);

    int getMoney();
    void changeMoney(int change);
    int getIntel();
    void changeIntel(int change);
    int getHappy();
    void changeHappy(int change);

    void alert(string attribute);

    string getName();

    int getPosition();
    void moveForward();

    int getScore();
};

#endif //PROJECT_1_CHARACTER_H