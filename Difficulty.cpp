/**
 * The Diffiulty class stores all the data for the difficulties in the game.
 * It allows for choosing a preset (Easy, Medium, Hard) or creating your own Custom rules.
 *
 * Creator: Luke Welton (law0047)
 * Filename: Difficulty.cpp
 *
 * The only external sources I used for this were for understanding the -> operator,
 * discussed in the header for System.cpp
 */

#include <iostream>
#include <cstdlib>
#include "Difficulty.h"

Difficulty::Difficulty(char preset) {
    switch (preset) {
        case 'H': {
            mapSize = 40;
            timeLimit = 55;
            attrInitMin = 3;
            attrInitMax = 12;
            attrDeltaMin = 3;
            attrDeltaMax = 10;
            puzzleDiff = 3;
            highScores = new ScoreList("hard_highScores.txt", "Hard");
            break;
        }
        case 'M': {
            mapSize = 30;
            timeLimit = 50;
            attrInitMin = 5;
            attrInitMax = 18;
            attrDeltaMin = 2;
            attrDeltaMax = 8;
            puzzleDiff = 2;
            highScores = new ScoreList("medium_highScores.txt", "Medium");
            break;
        }
        case 'E':
        default: {
            mapSize = 20;
            timeLimit = 40;
            attrInitMin = 8;
            attrInitMax = 20;
            attrDeltaMin = 1;
            attrDeltaMax = 5;
            puzzleDiff = 1;
            highScores = new ScoreList("easy_highScores.txt", "Easy");
            break;
        }
    }

    isCustom = false;
}

Difficulty::Difficulty(int sizeIn, int timeIn, int initMin, int initMax, int deltaMin, int deltaMax, int puzzle) {
    mapSize = sizeIn;
    timeLimit = timeIn;
    attrInitMin = initMin;
    attrInitMax = initMax;
    attrDeltaMin = deltaMin;
    attrDeltaMax = deltaMax;
    puzzleDiff = puzzle;
    isCustom = true;
}

int Difficulty::getMapSize() {
    return mapSize;
}

int Difficulty::getTimeLimit() {
    return timeLimit;
}

int Difficulty::getAttrInitMin() {
    return attrInitMin;
}

int Difficulty::getAttrInitMax() {
    return attrInitMax;
}

int Difficulty::getAttrDeltaMin() {
    return attrDeltaMin;
}

int Difficulty::getAttrDeltaMax() {
    return attrDeltaMax;
}

int Difficulty::getPuzzleDiff() {
    return puzzleDiff;
}

int Difficulty::getRandomAttrInit() {
    return rand() % (getAttrInitMax() + 1 - getAttrInitMin()) + getAttrInitMin();
}

int Difficulty::getRandomAttrDelta() {
    return rand() % (getAttrDeltaMax() + 1 - getAttrDeltaMin()) + getAttrDeltaMin();
}

void Difficulty::displayHighScores() {
    if (!isCustom) {
        highScores->printScores();
    }
    else {
        cout << "We're sorry, but we do not keep the high scores of Custom games." << endl;
        cout << "Play on a predefined difficulty for all the glory!" << endl;
    }
}

bool Difficulty::insertHighScore(int score, string name) {
    return !isCustom && highScores->insertScore(score, name);
}