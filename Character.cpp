/**
 * This class contains everything concerning the player throughout the game.
 * It keeps tracks of their stats and allowed modification of them.
 *
 * Creator: Luke Welton (law0047@auburn.edu)
 * Filename: Character.cpp
 *
 * I did not use any outside sources for this class.
 */

#include <iostream>
#include "Character.h"

Character::Character(int m, int i, int h, string nameIn) {
    money = m;
    intel = i;
    happy = h;
    position = 0;
    name = nameIn;
}

int Character::getMoney() {
    return money;
}
void Character::changeMoney(int change) {
    money += change;
    money = money < 0 ? 0 : money;
    if (money < 5) {
        alert("money");
    }
}

int Character::getIntel() {
    return intel;
}
void Character::changeIntel(int change) {
    intel += change;
    intel = intel < 0 ? 0 : intel;
    if (intel < 5) {
        alert("intelligence");
    }
}

int Character::getHappy() {
    return happy;
}
void Character::changeHappy(int change) {
    happy += change;
    happy = happy < 0 ? 0 : happy;
    if (happy < 5) {
        alert("happiness");
    }
}

void Character::alert(string attribute) {
    cout << "WARNING: Your " << attribute << " is running low!" << endl;
}

int Character::getPosition() {
    return position;
}

void Character::moveForward() {
    position += 1;
}

int Character::getScore() {
    return intel * money * happy;
}

string Character::getName() {
    return name;
}
