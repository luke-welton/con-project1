#ifndef PROJECT_1_DIFFICULTY_H
#define PROJECT_1_DIFFICULTY_H

#include "ScoreList.h"

class Difficulty {
private:
    int mapSize, timeLimit, attrInitMin, attrInitMax, attrDeltaMin, attrDeltaMax, puzzleDiff;
    ScoreList *highScores;
    bool isCustom;
public:
    Difficulty(char preset);
    Difficulty(int sizeIn, int timeIn, int initMin, int initMax, int deltaMin, int deltaMax, int puzzle);

    int getMapSize();
    int getTimeLimit();
    int getAttrInitMin();
    int getAttrInitMax();
    int getAttrDeltaMin();
    int getAttrDeltaMax();
    int getPuzzleDiff();

    int getRandomAttrInit();
    int getRandomAttrDelta();

    void displayHighScores();
    bool insertHighScore(int score, string name);
};

#endif //PROJECT_1_DIFFICULTY_H