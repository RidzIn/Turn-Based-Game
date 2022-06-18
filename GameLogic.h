//
// Created by 48724 on 17.06.2022.
//
#include <iostream>
#include "Unit.h"

#ifndef PASSWORDS_MANAGER_GAMELOGIC_H
#define PASSWORDS_MANAGER_GAMELOGIC_H
using namespace  std;

class GameLogic {
public:
    static string displayUnits(const vector<Unit>& player_pick);

    static bool is_miss(int chance_to_miss);

    static string player_hit(Unit &chosen_player_unit, Unit &unit_to_hit, const string& who);

    static int end_the_game();

    static string enemyAI(vector<Unit> &player_pick, vector<Unit> &enemy_pick, const string& who);

    static void incorrect_number(int start_number, int end_number);

    static double get_multiplier_damage(Unit &chosen_player_unit, Unit &unit_to_hit);

    static void print_game_manual();

    static string use_ultimate(Unit &chosen_player_unit, Unit &unit_to_hit, const string &who);


    static string heal(Unit &unit_to_heal, Unit &chosen_unit);

    static string earthquake(Unit &unit_to_heal, vector<Unit> &enemy_pick);

};


#endif //PASSWORDS_MANAGER_GAMELOGIC_H
