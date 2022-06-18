//
// Created by 48724 on 17.06.2022.
//
#include <iostream>
#include <utility>
#include "Unit.h"

using namespace std;


string Unit::to_string() const {
    string str1 = "-----------------------------\n";
    string str2 = "Name: " + name + '\n';
    string str3 = "Main Attribute: " + main_attribute + "\n";
    string str4 = "Agility: " + ::to_string(agility) + "\n";
    string str5 = "Strength: " + ::to_string(strength) + "\n";
    string str6 = "HP: " + ::to_string(hp) + "\n";
    string str7 = "EXP: " + ::to_string(exp) + "\n";
    string str8 = "TYPE: " + type + "\n";
    string str9 = "SUPER POWER: " + superPower.getName() + "\n";
    string str10 = "-----------------------------\n";

    return str1 + str2 + str3 + str4 + str5 + str6 + str7 + str8 + str9 + str10;
}

bool Unit::isDead() const {
    if (this->hp <= 0) {
        return true;
    }
    return false;
}

Unit::Unit(string name, string mainAttribute, int agility, int strength, int hp, int exp,
           Super_power superPower, string type) : name(std::move(name)), main_attribute(std::move(mainAttribute)),
                                                  agility(agility), strength(strength), hp(hp), exp(exp),
                                                  superPower(std::move(superPower)), type(std::move(type)) {}

void Unit::setAgility(int new_agility) {
    this->agility = new_agility;
}

void Unit::setStrength(int new_strength) {
    this->strength = new_strength;
}

void Unit::setHp(int new_hp) {
    this->hp = new_hp;
}

void Unit::setExp(int new_exp) {
    this->exp = new_exp;
}

Super_power Unit::getSuperPower() const {
    return superPower;
}
