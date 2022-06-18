//
// Created by 48724 on 15.06.2022.
//
#include <iostream>
#include "Super_power.h"
using namespace  std;
    Super_power::Super_power(const string &name, int damage) {
        this->name = name;
        this->damage = damage;
        this->isUsed = false;
    }


void Super_power::setIsUsed(bool used) {
    this->isUsed = used;
}

bool Super_power::getIsUsed() const {
    return isUsed;
}



