//
// Created by xurui on 2021/7/27.
//

#include "CPlayer.h"

int CPlayer::getNumber() const {
    return number;
}

void CPlayer::setNumber(int number) {
    CPlayer::number = number;
}

int CPlayer::getMoney() const {
    return money;
}

void CPlayer::setMoney(int money) {
    CPlayer::money = money;
}

void CPlayer::addMoney(int increment) {
    CPlayer::money = money + increment;
}
