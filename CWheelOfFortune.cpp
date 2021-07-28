//
// Created by xurui on 2021/7/27.
//

#include <ctime>
#include <algorithm>
#include <sstream>
#include "CWheelOfFortune.h"

void CWheelOfFortune::menu() {
    cout << "Welcome to the Wheel of Fortune..." << endl;
    cout << "----------------------------------" << endl;
    cout << "Quizmaster, please provide a word or sentence that the players need to guess:" << endl;
    string input_sentence;
    getline(cin, input_sentence);
    setSecretSentence(input_sentence);
}

void CWheelOfFortune::setSecretSentence(const string &secretSentence) {
    secret_sentence = secretSentence;
    temp_sentence = secret_sentence;
    //convert
    for (int i = 0; i < temp_sentence.size(); i++) {
        if(secret_sentence[i] == ' '){
            temp_sentence[i] = ' ';
        } else {
            temp_sentence[i] = '_';
        }
    }
}

void CWheelOfFortune::start() {
    cout << "Let the game begin!\n-------------------"<< endl;
    cout<< " " <<endl;
    cout << " " << endl;
    while(!gameOver){
        for (int i = 0;i < players.size();i++) {
            if(gameOver){
                break;
            } else {
                playerChoice(i);
            }
        }
    }
}

void CWheelOfFortune::preparation() {
    //init pools
    int temp = 100;
    for (int j = 0;j < 22;j++) {
        money_pools.push_back(temp);
        temp = temp + 100;
    }
    // init players
    for (int i = 0; i < 3;i++) {
        CPlayer nw_player{};
        nw_player.setNumber(i + 1);
        nw_player.setMoney(0);
        players.push_back(nw_player);
    }
}

void CWheelOfFortune::playerChoice(int index) {
    status();
    char choice = ' ';
    cout << "-- Player "<< index + 1 << "'s turn..." << endl;
    cout << endl;
    cout << "Your options:\n1) Turn the wheel and guess a letter.\n2) Guess the solution\nWhat would you like to do?" << endl;
    cin >> choice;
    cin.ignore();
    switch (choice) {
        case '1':
            spinWheel(index);
            break;
        case '2':
            guessSolution(index);
            break;
        default:
            playerChoice(index);
            break;
    }
}

void CWheelOfFortune::spinWheel(int index) {
    cout<<endl;
    cout << "Spinning the wheel!" << endl;
    srand((int)time(NULL));
    int random=rand()%money_pools.size();
    if(random == money_pools.size() -1){
        cout << "Oh no! The wheel ended on BANKRUPTCY! You lose all your money!" << endl;
        players[index].setMoney(0);
    } else if(random == money_pools.size() - 2) {
        cout << "Bad luck! The wheel ended on LOSE A TURN! Your turn is lost." << endl;
    } else {
        cout << "The arrow landed on "<< "$" << money_pools[random] << endl;
        char guessing_letter;
        cout << "Please enter a letter: ";
        cin >> guessing_letter;
        cin.ignore();
        checkLetter(guessing_letter,money_pools[random], index);
    }
}


void CWheelOfFortune::checkLetter(const char &letter,int increment, int index) {
    if(binary_search(used_chars.begin(),used_chars.end(),letter)){
        cout << "That letter does not occur in the solution (anymore)." << endl;
        return;
    } else {
        int sum = 0;
        for (int i = 0;i < secret_sentence.size();i++) {
            if(secret_sentence[i] == letter){
                temp_sentence[i] = letter;
                sum = sum + 1;
            }
        }
        if(sum != 0){
            cout << "That letter exists "<< sum <<" time(s) in the solution.\n"
                                                  "You have earned $" << (increment * sum) << endl;
            players[index].addMoney(increment * sum);
            used_chars.push_back(letter);
        } else {
            cout << "That letter does not occur in the solution (anymore)." << endl;
        }
    }
}

void CWheelOfFortune::guessSolution(int index) {
    string answer;
    cout << "Your guess?" <<endl;
    getline(cin,answer);
    if (secret_sentence == answer){
        cout << "Congratulations! You have guessed correctly.\n"
                "Game over! Player "<< (index + 1) <<" won the game and earned $"<< players[index].getMoney() << endl;
        gameOver = true;
    } else {
        cout << "Sorry, that's not correct!" << endl;
    }

}

void CWheelOfFortune::status() {
    cout<<endl;
    for (auto &player : players) {
        cout << "-- Money earned by player " << player.getNumber() <<": " <<  to_string(player.getMoney()) << endl;
    }
    cout << endl;
    cout << "The solution so far: " << temp_sentence  << endl;
    cout<<endl;
}
