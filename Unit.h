//
// Created by 48724 on 17.06.2022.
//
#include <iostream>
#include <vector>
#include <fstream>
#include "Super_power.h"

using namespace std;
#ifndef PASSWORDS_MANAGER_UNIT_H
#define PASSWORDS_MANAGER_UNIT_H


class Unit {
private:
    string name;
    string main_attribute;
    int agility;
    int strength;
    int hp;
    int exp;
    Super_power superPower;
    string type;
public:

    Unit(string name, string mainAttribute, int agility, int strength, int hp, int exp,
         Super_power superPower, string type);

    bool isDead() const;


    const string &getName() const {
        return name;
    }

    const string &getType() const {
        return type;
    }

    const string &getMainAttribute() const {
        return main_attribute;
    }

    int getAgility() const {
        return agility;
    }

    void setAgility(int new_agility);

    int getStrength() const {
        return strength;
    }

    void setStrength(int new_strength);

    int getHp() const {
        return hp;
    }

    void setHp(int new_hp);

    int getExp() const {
        return exp;
    }

    void setExp(int new_exp);

    string to_string() const;

    Super_power getSuperPower() const;
};


#endif //PASSWORDS_MANAGER_UNIT_H
