#ifndef PROJECT_1_MENU_H
#define PROJECT_1_MENU_H

#include <vector>
using namespace std;

class Menu {
private:
    vector<string> options;
    bool isChar;
public:
    Menu(int preset);

    void display();
    char getSelection();
};


#endif //PROJECT_1_MENU_H
