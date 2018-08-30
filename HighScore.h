#ifndef PROJECT_1_HIGHSCORE_H
#define PROJECT_1_HIGHSCORE_H

#include <string>
using namespace std;

class HighScore {
private:
    string name;
    int score;
public:
    HighScore(string nameIn, int scoreIn);
    HighScore();

    int getScore();
    string getName();
};


#endif //PROJECT_1_HIGHSCORE_H
