/**
 * The game class handles running through an instance of the game.
 * This way, an entirely different instance is created after the player return to the main menu.
 * Everything involving a single game is performed here.
 *
 * Creator: Luke Welton (law0047)
 * Filename: Game.cpp
 *
 * The only outside sources I used for this file were for the -> operator, discussed in the header for System.cpp
 **/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Game.h"
#include "Menu.h"
#include "System.h"
#include "Encounter.h"

using namespace std;

Game::Game(Difficulty *diffIn, string nameIn) {
    chosenDifficulty = diffIn;

    time = chosenDifficulty->getTimeLimit();
    mapSize = chosenDifficulty->getMapSize();

    int money = chosenDifficulty->getRandomAttrInit();
    int intel = chosenDifficulty->getRandomAttrInit();
    int happy = chosenDifficulty->getRandomAttrInit();
    player = new Character(money, intel, happy, nameIn);
}

void Game::run() {
    cout << "\n\n\nWelcome to Shelby Hall & Dragons!" << endl;
    cout << "In this game, you will walk through Shelby Hall and try to graduate on time!" << endl;
    cout << "Try to have as high of stats as possible for a high score, " << endl;
    cout << "But make sure you don't run out of time!" << endl << endl;

    cout << "This map will have " << mapSize << " spaces you must travel, ";
    cout << "with a time limit of " << chosenDifficulty->getTimeLimit() << "." << endl;
    cout << "You will begin with ";
    cout << player->getMoney() << " money, ";
    cout << player->getIntel() << " intelligence, and ";
    cout << player->getHappy() << " happiness." << endl << endl;

    cout << "Good luck, and have fun!" << endl;

    Menu turnMenu(2);
    while (!gameOver() && !isAtEnd()) {
        cout << endl << "What do you want to do?" << endl;
        turnMenu.display();
        int turnSelection = static_cast<int>(turnMenu.getSelection()) - 48;

        cout << endl;
        switch (turnSelection) {
            case 1: {
                move();
                break;
            }
            case 2: {
                read();
                break;
            }
            case 3: {
                work();
                break;
            }
            case 4: {
                play();
                break;
            }
            case 5: {
                viewStats();
                break;
            }
            case 6:
            default: {
                giveUp();
                return;
            }
        }
    }

    cout << endl << endl;

    if (gameOver() && !isAtEnd()) {
        if (time <= 0) {
            cout << "You spent too much time pursuing your graduate's degree, and life flies right by." << endl;
            cout << "After some time, you decide to simply give up on the degree and return home." << endl;
        }
        else if (player->getMoney() <= 0) {
            cout << "You run out of money while pursuing your graduate's degree," << endl;
            cout << "Preventing you from paying for your classes." << endl;
            cout << "You don't feel like you can afford even student loans, and so you give up and return home." << endl;
        }
        else if (player->getHappy() <= 0) {
            cout << "Without dedicating any free time, you overwork yourself into depression." << endl;
            cout << "You lose all motivation to attend classes, and eventually drop out." << endl;
            cout << "You guess you can return home, although even that doesn't excite you too much." << endl;
        }
        else {
            cout << "From a lack of studying and likely too much partying," << endl;
            cout << "You simply lack the intelligence to continue pursuing your graduate degree." << endl;
            cout << "The classes become too difficult to handle, and so you drop out and return home." << endl;
        }
    }
    else {
        cout << "Congratulations, you received your graduate degree from Auburn University!" << endl;
        cout << "You've never been more proud of yourself than this moment in your entire life!" << endl;
        cout << endl << "Your total score was: " << player->getScore() << endl;

        bool isNewHighScore = chosenDifficulty->insertHighScore(player->getScore(), player->getName());
        if (isNewHighScore) {
            cout << endl << "Congratulations! You reached a new high score!" << endl;
            chosenDifficulty->displayHighScores();
        }
    }

    cout << endl << endl << endl;
}

void Game::move() {
    cout << "You walk forward, and..." << endl;

    player->moveForward();
    time--;

    int encounterNum = System::getRandomInt(1, 100);
    encounterNum = static_cast<int>(ceil(encounterNum / 11));

    if (encounterNum <= 8) {
        Encounter event(chosenDifficulty->getPuzzleDiff(), encounterNum);
        bool error = event.displayIntro();
        if (!error) {
            bool correct = event.answerEncounter();
            char attrToChange = event.getAttr();

            if (correct) {
                int statChange = chosenDifficulty->getRandomAttrDelta();
                switch (attrToChange) {
                    case 'M': {
                        cout << "You gained " << statChange << " money, but lost 1 turn." << endl;
                        player->changeMoney(statChange);
                        time--;
                        break;
                    }
                    case 'I': {
                        cout << "Correct!" << endl;
                        cout << "You gained " << statChange << " intelligence!" << endl;
                        player->changeIntel(statChange);
                        break;
                    }
                    case 'H': {
                        cout << "You gained " << statChange << " happiness, but lost 1 turn." << endl;
                        player->changeHappy(statChange);
                        time--;
                        break;
                    }
                    default: {
                        cout << "You didn't gain any stats." << endl;
                    }
                }
            }
            else {
                if (attrToChange == 'I') {
                    cout << "Wrong!" << endl;
                    int statChange = chosenDifficulty->getRandomAttrDelta();
                    cout << "You lost " << statChange << " intelligence." << endl;
                    player->changeIntel(-1*statChange);
                }
                else {
                    cout << "You choose not to." << endl;
                    cout << "Your life goes on as normal." << endl;
                }
            }
        }
    }
    else {
        cout << "Nothing happens." << endl;
    }
}

void Game::read() {
    string readings[5] = {"books",
                          "periodicals",
                          "articles",
                          "technical papers",
                          "textbooks" };

    cout << "You decide to read some " << readings[rand() % 5] << "." << endl;
    int increase = chosenDifficulty->getRandomAttrDelta();
    player->changeIntel(increase);
    cout << "You gained " << increase << " intelligence!" << endl;
    time--;
}
void Game::work() {
    string jobs[5] = {"search for loose change",
                      "sell some old games",
                      "sell some old clothes",
                      "mow your neighbor's lawn",
                      "walk your friend's dog"};

    cout << "You decide to " << jobs[rand() % 5] << "." << endl;
    int increase = chosenDifficulty->getRandomAttrDelta();
    player->changeMoney(increase);
    cout << "You gained " << increase << " money!" << endl;
    time--;
}
void Game::play() {
    string games[5] = {"Grand Theft Airplane",
                       "Marsbound",
                       "The Legend of Robin",
                       "Super Giorgio Bros",
                       "Underwatch"};

    cout << "You decide to play " << games[rand() % 5] << "." << endl;
    int increase = chosenDifficulty->getRandomAttrDelta();
    player->changeHappy(increase);
    cout << "You gained " << increase << " happiness!" << endl;
    time--;
}

void Game::viewStats() {
    cout << "Here are your current stats:" << endl;
    cout << "Money:\t\t" << player->getMoney() << endl;
    cout << "Intelligence:\t" << player->getIntel() << endl;
    cout << "Happiness:\t" << player->getHappy() << endl;
    cout << "Position:\t" << player->getPosition() << "/" << mapSize << endl;
    cout << "Time Remaining:\t" << time << endl;
}

void Game::giveUp() {
    cout << "\"We're sorry Auburn was too difficult for you," << endl;
    cout << "Feel free to come back and try again!\"" << endl;
    cout << "You decide to drop out of your graduate program." << endl;
    cout << "You spend the rest of your life regretting this decision, " << endl;
    cout << "But you can't ever bring yourself to go back to classes." << endl << endl << endl << endl;
}

bool Game::isAtEnd() {
    return player->getPosition() >= mapSize;
}

bool Game::gameOver() {
    return time <= 0 || player->getHappy() <= 0 || player->getIntel() <= 0 || player->getMoney() <= 0;
}
