/**
 * This class stores the data for each indicidual High Score chart
 * As there are multiple difficulties, this is generalized enough for each one.
 * That said, it would take a good bit of restructuring to handle anything other than 10 entries.
 * But it works for the purpose I need it to.
 *
 * Creator: Luke Welton (law0047)
 * Filename: ScoreList.cpp
 *
 * I used a number of external sources here.
 *
 * For unsigned->signed int conversion (lines 59 & 92) , Mystacial on stackoverflow helped
 *  (http://stackoverflow.com/questions/8317295/convert-unsigned-int-to-signed-int-c)
 *
 * For using ifstream/ofstream as a boolean to check for failure (lines 37 & 104), Antoniio and Filip Roseen from stackoverflow helped
 *  (http://stackoverflow.com/questions/24097580/ifstreamis-open-vs-ifstreamfail)
 *
 * And for the left command on cout (line 126), I used http://www.cplusplus.com/reference/ios/left/
 **/

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "ScoreList.h"
#include "System.h"

ScoreList::ScoreList(string fileIn, string nameIn) {
    listName = nameIn;
    fileName = fileIn;
    longestName = 8;

    ifstream inStream;
    inStream.open((char*)fileName.c_str());

    int tries = 0;
    while (!inStream && tries < 100) {
        inStream.close();
        writeToFile(fileName, true);
        inStream.open((char*)fileName.c_str());
        tries++;
    }

    if (tries >= 100) {
        cout << "An error occurred trying to open a High Score file." << endl;
        exit(1);
    }

    for (int i = 0; i < 10; i++) {
        string hsName = "";
        int hsScore = 0;

        inStream >> hsName;
        inStream >> hsScore;

        HighScore hs(hsName, hsScore);
        scores[i] = hs;

        if ((int) hsName.size() > longestName) {
            longestName = hsName.size() + 1;
        }
    }

    inStream.close();
}

int ScoreList::findInsertPosition(int score) {
    int pos = -1;
    int index = 9;

    while (score >= scores[index].getScore() && index > -1) {
        pos = index;
        index--;
    }

    return pos;
}

bool ScoreList::insertScore(int score, string name) {
    int newPosition = findInsertPosition(score);

    if (newPosition > -1) {
        HighScore newHighScore(name, score);

        for (int i = 9; i > newPosition; i--) {
            scores[i] = scores[i-1];
        }
        scores[newPosition] = newHighScore;

        writeToFile(fileName, false);

        if ((int) name.size() > longestName) {
            longestName = name.size() + 1;
        }
    }

    return newPosition > -1;
}

void ScoreList::writeToFile(string fileName, bool isCreating) {
    ofstream outStream;
    outStream.open((char*)fileName.c_str());

    if (outStream) {
        if (isCreating) {
            for (int i = 10000; i >= 0; i -= 1000) {
                outStream << System::getRandomFirstName() << "\n" << i << endl;
            }
        } else {
            for (int i = 0; i < 10; i++) {
                outStream << scores[i].getName() << "\n" << scores[i].getScore() << endl;
            }
        }
    }
    else {
        cout << "An error occurred writing to the file." << endl;
        exit(1);
    }

    outStream.close();
}

void ScoreList::printScores() {
    cout <<  "\n  === " << listName << " High Scores ===" << endl;
    for (int i = 0; i < 10; i++) {
         cout << "\t" << setw(longestName) << left << scores[i].getName()  << scores[i].getScore() << endl;
    }
    cout << endl;
}