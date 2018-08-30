/**
 * The menu class handles running through selections within the game.
 * It is passed a vector of options, and then handles any selections performed by the user.
 *
 * Creator: Luke Welton (law0047)
 * Filename: Menu.cpp
 *
 * The external sources I used are for the -> operator and for knowing to add '0' to an int for int->char conversion.
 * Both are discussed in the header for System.cpp.
 **/

#include <iostream>
#include <stdlib.h>
#include "Menu.h"
#include "System.h"

Menu::Menu(int preset) {
    switch (preset) {
        //Main Menu
        case 0: {
            options.push_back("Start a new game");
            options.push_back("View high scores");
            options.push_back("Exit game");
            isChar = false;
            break;
        }
        //Difficulty Selector
        case 1: {
            options.push_back("Easy");
            options.push_back("Medium");
            options.push_back("Hard");
            options.push_back("Custom");
            isChar = true;
            break;
        }
        //In-game Menu
        case 2: {
            options.push_back("Move forward.");
            options.push_back("Read.");
            options.push_back("Do some work.");
            options.push_back("Play a game.");
            options.push_back("View current stats.");
            options.push_back("Give up.");
            isChar = false;
            break;
        }
        //Difficulty w/o Custom
        case 3: {
            options.push_back("Easy");
            options.push_back("Medium");
            options.push_back("Hard");
            isChar = true;
            break;
        }
        default: {
            isChar = false;
            break;
        }
    }
}

void Menu::display() {
    for (unsigned i = 0; i < options.size(); i++) {
        cout << "\t";
        if (!isChar) {
            cout << (i + 1) << ". ";
        }
        cout << options[i] << endl;
    }
    cout << (isChar ? "Enter the first letter of the option." : "Enter the number before the option.") << endl;
}

char Menu::getSelection() {
    vector<char> valid;
    for (unsigned i = 0; i < options.size(); i++) {
        if (isChar) {
            valid.push_back(options[i][0]);
        }
        else {
            valid.push_back('0' + i + 1);
        }
    }

    return System::charLoop(valid);
}