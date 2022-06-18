//
// Created by 48724 on 15.06.2022.
//
#include <iostream>
#ifndef PASSWORDS_MANAGER_SUPER_POWER_H
#define PASSWORDS_MANAGER_SUPER_POWER_H

using namespace  std;
class Super_power {
private:
    string name;
    int damage;
    bool isUsed;
public:
    Super_power(const string &name, int damage);

    const string &getName() const { return name;}

    int getDamage() const {return damage;}

    void setIsUsed(bool isUsed);

    bool getIsUsed() const;
};

#endif //PASSWORDS_MANAGER_SUPER_POWER_H
