#ifndef PROJECT_1_SCORELIST_H
#define PROJECT_1_SCORELIST_H

#include "HighScore.h"

class ScoreList {
private:
    HighScore scores[10];
    string listName, fileName;
    int longestName;
public:
    ScoreList(string fileIn, string nameIn);

    int findInsertPosition(int score);
    bool insertScore(int score, string name);

    void printScores();

    void writeToFile(string fileName, bool isCreating);
};


#endif //PROJECT_1_SCORELIST_H
