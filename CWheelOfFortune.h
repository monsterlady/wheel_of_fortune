//
// Created by xurui on 2021/7/27.
//

#ifndef WHEEL_OF_FORTUNE_CWHEELOFFORTUNE_H
#define WHEEL_OF_FORTUNE_CWHEELOFFORTUNE_H
#include "iostream"
#include "vector"
#include "CPlayer.h"

using namespace std;

class CWheelOfFortune {
private:
    string temp_sentence;
    string secret_sentence;
    vector<int> money_pools;
    vector<CPlayer> players;
    vector<char> used_chars;
    bool gameOver = false;

public:
    void preparation();

    void menu();

    void status();

    void start();

    void playerChoice(int index);

    void spinWheel(int index);

    void guessSolution(int index);

    void setSecretSentence(const string &secretSentence);

    void checkLetter(const char &letter, int increment, int index);
};


#endif //WHEEL_OF_FORTUNE_CWHEELOFFORTUNE_H
