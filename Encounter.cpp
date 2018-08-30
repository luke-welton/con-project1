/**
 * This class handles the Encounters that can occur whenever the player moves forward.
 *
 * I am so sorry to whoever reads this it's so badly written
 * It was the first thing I started on and I didn't really have a good idea of what I wanted to do
 * I wish I could go back and redo this but I think that'll take too much time :'(
 *
 * Creator: Luke Welton (law0047)
 * Filename: Encounter.cpp
 *
 * I did not use any outside sources for this file.
 **/

#include <cstdlib>
#include <iostream>
#include "Encounter.h"
#include "System.h"

Encounter::Encounter(int diff, int t) {
    difficulty = diff;
    type = t == 0 ? rand() % 8 + 1 : t;
}

bool Encounter::displayIntro() {
    string encounterMessage = "";
    bool noEncounter = false;

    switch (type) {
        case 1: {
            encounterMessage = "You ran into Dr. " + System::getRandomLastName() + "!\n";
            encounterMessage += "\"I'm looking for someone to help me grade some papers.\"\n"
                    "\"Would you like to help out?\" (Y/N)";
            break;
        }
        case 2: {
            encounterMessage = "You ran into Dr. " + System::getRandomLastName() + "!\n";
            encounterMessage += "\"Pop quiz time!\"\n"
                    "\"But I'm not even class!\" you say.\n"
                    "\"Too bad!\"\n";

            int quiz = rand() % 3;
            switch (quiz) {
                case 3: {
                    type = 23;
                    switch (difficulty) {
                        case 3: {
                            encounterMessage += "What is the derivative of 140,231 with respect to z?";
                            break;
                        }
                        case 2: {
                            encounterMessage += "What is tan(135) in degrees?";
                            break;
                        }
                        case 1:
                        default: {
                            encounterMessage += "What is 22 + 49?";
                            break;
                        }
                    }
                    break;
                }
                case 2: {
                    type = 22;
                    switch (difficulty) {
                        case 3: {
                            encounterMessage += "What is the fear of colors?";
                            break;
                        }
                        case 2: {
                            encounterMessage += "Which of Newton's Laws of Physics reads as following:\n"
                                                "An object in motion tends to stay in motion unless acted upon by an outside force.\n"
                                                "(Enter an Integer): ";
                            break;
                        }
                        case 1:
                        default: {
                            encounterMessage += "What is the study of rocks?";
                            break;
                        }
                    }
                    break;
                }
                case 1:
                default: {
                    type = 21;
                    switch (difficulty) {
                        case 3: {
                            encounterMessage += "What programming language is this program written in?";
                            break;
                        }
                        case 2: {
                            encounterMessage += "What kind of loop is used in programming\n"
                                                "to iterate a series of statements a set number of times?";
                            break;
                        }
                        case 1:
                        default: {
                            encounterMessage += "What is 5 % 3?";
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        }
        case 3: {
            encounterMessage = "You ran into your friend " + System::getRandomFirstName() + "!\n";
            encounterMessage += "\"There's a party going on at " + System::getRandomFirstName() + "'s place,\"\n";
            encounterMessage += "\"Do you wanna join?\" (Y/N)";
            break;
        }
        case 4: {
            encounterMessage = "You ran into your friend " + System::getRandomFirstName() + "!\n";
            encounterMessage += "\"Do you think you could help me out with this project?\"\n"
                    "\"I'll pay you.\" (Y/N)";
            break;
        }
        case 5: {
            encounterMessage = "You ran into a job recruiter!\n"
                    "\"You look like a smart, dependable grad student!\"\n"
                    "\"Would you like to work part-time at my company?\" (Y/N)";
            break;
        }
        case 6: {
            encounterMessage = "You found a puzzle on the floor!\n";
            switch (difficulty) {
                case 3: {
                    encounterMessage += "What is the limit of 1/(n^2-1) as n goes to infinity?";
                    break;
                }
                case 2: {
                    encounterMessage += "What is the square root of 1156?";
                    break;
                }
                case 1:
                default: {
                    encounterMessage += "What is 2 + 2?";
                    break;
                }
            }
            break;
        }
        case 7: {
            encounterMessage = "You found a pizza on the floor!\n"
                               "Would you like to eat it? (Y/N)";
            break;
        }
        case 8: {
            encounterMessage = "A wild puzzle appeared!\n";
            switch (difficulty) {
                case 3: {
                    encounterMessage += "What is the name of the company that made Pokemon Go?";
                    break;
                }
                case 2: {
                    encounterMessage += "What is the name of the company who distributes Pokemon games?";
                    break;
                }
                case 1:
                default: {
                    encounterMessage += "What is the name of Pokemon's mascot?";
                    break;
                }
            }
            break;
        }
        default: {
            encounterMessage = "You thought you heard someone call your name in the hallway,\n"
                    "But you looked behind you and didn't see anyone.\n"
                    "That was weird.";
            noEncounter = true;
            break;
        }
    }
    cout << encounterMessage << endl;
    return noEncounter;
}

bool Encounter::answerEncounter() {
    string answer;

    bool correct = false;
    switch (type) {
        case 23: {
            cin >> answer;
            switch (difficulty) {
                case 3: {
                    correct = answer == "0";
                    break;
                }
                case 2: {
                    correct = answer == "1";
                    break;
                }
                case 1: {
                    correct = answer == "71";
                    break;
                }
            }
            break;
        }
        case 22: {
            cin >> answer;
            switch (difficulty) {
                case 3: {
                    System::toLowerCase(answer);
                    correct = answer == "chromophobia" || answer == "chromatophobia";
                    break;
                }
                case 2: {
                    correct = answer == "1";
                    break;
                }
                case 1: {
                    System::toLowerCase(answer);
                    correct = answer == "geology";
                    break;
                }
            }
            break;
        }
        case 21: {
            cin >> answer;
            switch (difficulty) {
                case 3: {
                    System::toUpperCase(answer);
                    correct = answer == "C++";
                    break;
                }
                case 2: {
                    System::toLowerCase(answer);
                    correct = answer == "for" || answer == "for loop";
                    break;
                }
                case 1: {
                    correct = answer == "2";
                    break;
                }
            }
            break;
        }
        case 6: {
            cin >> answer;
            switch (difficulty) {
                case 3: {
                    correct = answer == "0";
                    break;
                }
                case 2: {
                    correct = answer == "34";
                    break;
                }
                case 1: {
                    correct = answer == "4";
                    break;
                }
            }
            break;
        }
        case 8: {
            cin >> answer;
            System::toLowerCase(answer);
            switch (difficulty) {
                case 3: {
                    correct = answer == "niantic";
                    break;
                }
                case 2: {
                    correct = answer == "nintendo";
                    break;
                }
                case 1: {
                    correct = answer == "pikachu";
                    break;
                }
            }
            break;
        }
        case 1: case 3: case 4:
        case 5: case 7: default: {
            vector<char> yn;
            yn.push_back('Y');
            yn.push_back('N');
            answer = System::charLoop(yn);
            correct = answer == "Y";
            break;
        }
    }

    return correct;
}

char Encounter::getAttr() {
    switch (type) {
        case 1: case 4:
        case 5: {
            return 'M';
        }
        case 3: case 7:{
            return 'H';
        }
        case 21: case 22: case 23:
        case 6: case 8: {
            return 'I';
        }
        default: {
            return 'R';
        }
    }
}