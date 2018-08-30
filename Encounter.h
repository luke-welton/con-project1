#ifndef PROJECT_1_ENCOUNTER_H
#define PROJECT_1_ENCOUNTER_H

using namespace std;

class Encounter{
private:
    int type;
    int difficulty;
public:
    Encounter(int diff, int t = 0);

    bool displayIntro();
    bool answerEncounter();

    char getAttr();
};

#endif //PROJECT_1_ENCOUNTER_H