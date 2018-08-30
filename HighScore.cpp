/**
 * This is a small little class that I used to store data for the ScoreList
 * I did it this way so I could have one vector in ScoreList instead of two
 * I think this should technically be a structure? But I don't really know how those work.
 *
 * Creator: Luke Welton (law0047)
 * Filename: HighScore.cpp
 *
 * I did not use any external sources for this file.
 **/

#include "HighScore.h"
#include "System.h"

HighScore::HighScore(string nameIn, int scoreIn) {
    name = nameIn;
    score = scoreIn;
}

HighScore::HighScore() {
    name = System::getRandomFirstName();
    score = 0;
}

string HighScore::getName() {
    return name;
}

int HighScore::getScore() {
    return score;
}