/**
 * This file provides the background System for the entire game.
 * That is, this works with everything on the main menu,
 * and stores anything that might be necessary to start a new game.
 * It also houses a lot of static methods used by various other classes.
 *
 * Creator: Luke Welton (law0047@auburn.edu)
 * Filename: System.cpp
 *
 * I mostly wrote this by myself.
 * However, finding out I needed to subtract 48 for char->int conversion (line 165) was thanks to
 * Adrian Shum on stackoverflow (http://stackoverflow.com/questions/16349817/how-to-convert-an-int-to-a-char-c)
 * Plus a little logic on my part.
 *
 * Also, I learned about the arrow operator through seeing it at
 *  http://stackoverflow.com/questions/27445814/correct-way-to-store-objects-in-another-object-in-c
 * and learning more about what it does through Athar on cplusplus.com (http://www.cplusplus.com/forum/beginner/53293/)
 * This is used /a lot/ throughout this project,
 * but since this is a specific operator and not code, I hope this is okay for referencing.
 **/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "System.h"
#include "Menu.h"
#include "Game.h"

System::System() {
    srand(time(0));

    easy = new Difficulty('E');
    medium = new Difficulty('M');
    hard = new Difficulty('H');

    name = "Morgan";
}

int System::intLoop(int min, int max) {
    int returnVal = 0;
    if (min > max) {
        do {
            cin >> returnVal;
            if (returnVal <= min) {
                cout << "Please enter a valid number greater than " << min << endl;
            }
        } while (returnVal <= min);
    }
    else {
        do {
            cin >> returnVal;
            if (returnVal < min || returnVal > max) {
                cout << "Please enter a valid number within " << min << "-" << max << endl;
            }
        } while (returnVal < min || returnVal > max);
    }

    return returnVal;
}

bool System::contains(vector<char> v, char c) {
    for (unsigned i = 0; i < v.size(); i++) {
        if (v[i] == c) {
            return true;
        }
    }

    return false;
}

char System::charLoop(vector<char> acceptedInputs) {
    char returnChar = '?';

    int run = 0;
    do {
        run++;
        if (run > 1) {
            cout << "Please enter a valid input." << endl;
        }

        cin >> returnChar;
        returnChar = static_cast<char>(toupper(returnChar));
    } while (!contains(acceptedInputs, returnChar));

    return returnChar;
}

void System::toUpperCase(string& s) {
    for (unsigned i = 0; i < s.size(); i++) {
        s[i] = static_cast<char>(toupper(s[i]));
    }
}

void System::toLowerCase(string& s) {
    for (unsigned i = 0; i < s.size(); i++) {
        s[i] = static_cast<char>(tolower(s[i]));
    }
}

string System::getRandomFirstName() {
    string firstName[15] = {"Luke",
                            "Nicole",
                            "David",
                            "Rebecca",
                            "Lily",
                            "Dylan",
                            "Bryant",
                            "Rei",
                            "Ash",
                            "Scott",
                            "Cole",
                            "Lea",
                            "Miranda",
                            "Chloe",
                            "Amber"};

    return firstName[rand() % 15];
}
string System::getRandomLastName() {
    string lastNames[15] = { "Ku",
                             "Kirby",
                             "Whitt",
                             "Venkatasubramanian",
                             "Daly",
                             "Gong",
                             "Li",
                             "Chidume",
                             "Smith",
                             "Karcher",
                             "Hunter",
                             "Hendrix",
                             "Cross",
                             "Manning",
                             "Hebert" };

    return lastNames[rand() % 15];
}

int System::getRandomInt(int min, int max) {
    return rand() % (++max - min) + min;
}

void System::displayIntro() {
    cout << "Hello, and welcome to Shelby Center & Dragons!" << endl;
    cout << "Before we begin, what is your name?" << endl;
    cin >> name;

    string box = "========";
    box += "=========";
    for (unsigned i = 0; i < name.size(); i++) {
        box += "=";
    }
    box += "========";

    cout << endl << box << endl;
    cout << "|\tWelcome, " << name << "!      |" << endl;
    cout << box << endl << endl;
}

bool System::displayMainMenu(){
    Menu mainMenu(0);

    cout << "Please select an option." << endl;
    mainMenu.display();
    int selection = static_cast<int>(mainMenu.getSelection()) - 48;

    switch (selection) {
        //New Game
        case 1: {
            Menu diffMenu(1);
            cout << endl << "Select a Difficulty:" << endl;
            diffMenu.display();
            char diffSelection = diffMenu.getSelection();

            Difficulty *chosenDifficulty;
            switch (diffSelection) {
                case 'C': {
                    int map = 0, cTime = 0, initMin = 0, initMax = 0, deltaMin = 0, deltaMax = 0, puzzle = 0;
                    cout << endl;

                    cout << "How long should the map be?\t";
                    map = intLoop(0, -1);

                    cout << "How much time should you have?\t";
                    cTime = intLoop(0, -1);

                    cout << "What should the minimum starting value for stats be?\t";
                    initMin = intLoop(0, -1);

                    cout << "What about the maximum value?\t";
                    initMax = intLoop(initMin - 1, -1);

                    cout << "What should the minimum change in stats be?\t";
                    deltaMin = intLoop(0, -1);

                    cout << "What about the maximum value?\t";
                    deltaMax = intLoop(deltaMin - 1, -1);

                    cout << "On a scale of 1-3, how difficult should the puzzles be?\t";
                    puzzle = intLoop(1, 3);

                    chosenDifficulty = new Difficulty(map, cTime, initMin, initMax, deltaMin, deltaMax, puzzle);
                    break;
                }
                case 'H': {
                    chosenDifficulty = hard;
                    break;
                }
                case 'M': {
                    chosenDifficulty = medium;
                    break;
                }
                case 'E':
                default: {
                    chosenDifficulty = easy;
                    break;
                }
            }

            Game currentGame(chosenDifficulty, name);
            currentGame.run();

            return false;
        }
        //High Scores
        case 2: {
            Menu diffMenu(3);
            cout << endl << "Which difficulty would you like to see?" << endl;
            diffMenu.display();
            char diffSelection = diffMenu.getSelection();

            switch (diffSelection) {
                case 'E': {
                    easy->displayHighScores();
                    break;
                }
                case 'M': {
                    medium->displayHighScores();
                    break;
                }
                case 'H': {
                    hard->displayHighScores();
                    break;
                }
                default: {
                    cout << "Uh oh! Something went wrong!" << endl;
                    break;
                }
            }

            return false;
        }
        //Exit Game
        case 3:
        default: {
            cout << "Goodbye!" << endl;
            return true;
        }
    }
}