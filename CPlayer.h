//
// Created by xurui on 2021/7/27.
//

#ifndef WHEEL_OF_FORTUNE_CPLAYER_H
#define WHEEL_OF_FORTUNE_CPLAYER_H


class CPlayer {
private:
    int number;
    int money;
public:
    int getNumber() const;

    void setNumber(int number);

    int getMoney() const;

    void setMoney(int money);

    void addMoney(int increment);

};


#endif //WHEEL_OF_FORTUNE_CPLAYER_H
