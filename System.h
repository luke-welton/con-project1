#ifndef PROJECT_1_SYSTEM_H
#define PROJECT_1_SYSTEM_H

#include <string>
#include <vector>
#include "Difficulty.h"
using namespace std;

class System {
private:
    Difficulty *easy, *medium, *hard;
    string name;
public:
    System();

    static bool contains(vector<char> v, char c);

    static int intLoop(int min, int max);
    static char charLoop(vector<char> acceptedInputs);

    static void toUpperCase(string& s);
    static void toLowerCase(string& s);

    static string getRandomFirstName();
    static string getRandomLastName();
    static int getRandomInt(int min, int max);

    void displayIntro();
    bool displayMainMenu();
};

#endif //PROJECT_1_SYSTEM_H