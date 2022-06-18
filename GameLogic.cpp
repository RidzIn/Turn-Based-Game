//
// Created by 48724 on 17.06.2022.
//

#include "GameLogic.h"
#include <random>
using namespace  std;

string GameLogic::displayUnits(const vector<Unit>& player_pick) {
    string result;
    for(int i = 0; i < player_pick.size(); i++){
        result += "(" + ::to_string(i+1) + ") " + player_pick.at(i).getName() + " (" + ::
        to_string(player_pick.at(i).getHp()) + ")" + " (" + ::to_string(player_pick.at(i).getExp()) + ")" +"\n";
        cout << "(" << i+1 << ") " << player_pick.at(i).getName() << " (" <<player_pick.at(i).getHp() << ")" <<
        "(" << player_pick.at(i).getExp() << ")" << " (" << player_pick.at(i).getSuperPower().getIsUsed() << ")" <<"\n";
    }
    return result;
}

bool GameLogic::is_miss(int chance_to_miss) {
    std::random_device random_device; // create object for seeding
    std::mt19937 engine{random_device()}; // create engine and seed it

    std::uniform_int_distribution<> dist1(0,10);
    int random = dist1(engine);
    if( random > chance_to_miss){
        return false;
    }
    return true;
}

string GameLogic::player_hit(Unit &chosen_player_unit, Unit &unit_to_hit, const string& who) {
    string log;
    if(is_miss(unit_to_hit.getAgility())){
        log =  who + " MISSED\n";
    } else {
        int received_damage = (int)(chosen_player_unit.getStrength() * get_multiplier_damage(chosen_player_unit,unit_to_hit));
        chosen_player_unit.setExp(chosen_player_unit.getExp() + chosen_player_unit.getStrength());
        unit_to_hit.setHp(unit_to_hit.getHp() - received_damage);
        cout << unit_to_hit.getName() << " got damage: " << received_damage<< '\n';
        log = unit_to_hit.getName() + " got damage: " + ::to_string(received_damage) + '\n';
    }
    return log;
}



int GameLogic::end_the_game() {
    cout << "Open log file to see game history and result\n";
    cout << "Thank you a lot for playing my game. Good Luck!";
    return 0;
}

string GameLogic::enemyAI(vector<Unit> &player_pick, vector<Unit> &enemy_pick, const string& who) {

    string log;

    std::random_device random_device; // create object for seeding
    std::mt19937 engine{random_device()}; // create engine and seed it

    std::uniform_int_distribution<> dist1(0,(int)player_pick.size()-1);
    int random_player_unit = dist1(engine);

    std::uniform_int_distribution<> dist2(0,(int)enemy_pick.size()-1);
    int random_enemy_unit = dist2(engine);

        if(is_miss(player_pick.at(random_player_unit).getAgility())){
            log = who + " MISSED\n";
        } else{
            if(player_pick.at(random_player_unit).isDead()){
                player_pick.erase(player_pick.begin()+random_player_unit);
            } else {
                player_pick.at(random_player_unit)
                        .setHp(player_pick.at(random_player_unit).getHp()-(enemy_pick.at(random_enemy_unit).getStrength()));
                log = player_pick.at(random_player_unit).getName() + " got damage " + ::to_string(enemy_pick.at(random_enemy_unit).getStrength()) + "\n";
            }

        }
    return log;
}

void GameLogic::incorrect_number(int start_number, int end_number) {
    cout << "Please enter number between (" << start_number << " : " << end_number << ")\n";
}

double GameLogic::get_multiplier_damage(Unit &chosen_player_unit, Unit &unit_to_hit) {
    const string& player_attribute = chosen_player_unit.getMainAttribute();
    const string& enemy_attribute = unit_to_hit.getMainAttribute();
    // water
    if(player_attribute == "water"){
        if(enemy_attribute == "water"){
            return 0.5;
        }
        if(enemy_attribute == "ground"){
            return 2;
        }
        if(enemy_attribute == "fire"){
            return 2;
        }
        else {
            return 1;
        }
    }
    // fire
    if(player_attribute == "fire"){
        if(enemy_attribute == "water"){
            return 0.5;
        }
        if(enemy_attribute == "ground"){
            return 0.5;
        }
        if(enemy_attribute == "ice"){
            return 2;
        }
        if(enemy_attribute == "metal"){
            return 2;
        }
        else {
            return 1;
        }
    }
    // wind
    if(player_attribute == "wind"){
        if(enemy_attribute == "metal"){
            return 0.5;
        }
        if(enemy_attribute == "ground"){
            return 0.5;
        }
        if(enemy_attribute == "ice"){
            return 2;
        }
        else {
            return 1;
        }
    }
    // ice
    if(player_attribute == "ice"){
        if(enemy_attribute == "water"){
            return 0.5;
        }
        if(enemy_attribute == "ground"){
            return 2;
        }
        if(enemy_attribute == "ice"){
            return 0.5;
        }
        if(enemy_attribute == "fire"){
            return 0.5;
        }
        else {
            return 1;
        }
    }
    //metal
    if(player_attribute == "metal"){
        if(enemy_attribute == "water"){
            return 2;
        }
        if(enemy_attribute == "wind"){
            return 2;
        }
        if(enemy_attribute == "metal"){
            return 0.5;
        }
        if(enemy_attribute == "fire"){
            return 0.5;
        }
        else {
            return 1;
        }
    }
    // ground
    if(player_attribute == "ground"){
        if(enemy_attribute == "ice"){
            return 2;
        }
        if(enemy_attribute == "wind"){
            return 0.5;
        }
        if(enemy_attribute == "metal"){
            return 2;
        }
        if(enemy_attribute == "fire"){
            return 2;
        }
        else {
            return 1;
        }
    }
    return 0;
}

void GameLogic::print_game_manual() {
    std::ifstream help;
    help.open(R"(C:\Users\48724\CLionProjects\passwords_manager\help)");
    if(help.is_open()){
        char str;
        while(help){
            str = (char)help.get();
            cout << str;
        }
    }
    help.close();
}

string GameLogic::use_ultimate(Unit &chosen_player_unit, Unit &unit_to_hit, const string& who) {
    Super_power player_ulti = chosen_player_unit.getSuperPower();
    string log;
    if(player_ulti.getName() == "ball" || player_ulti.getName() == "strike"){
        int received_damage = (int)(player_ulti.getDamage() * get_multiplier_damage(chosen_player_unit,unit_to_hit));
        chosen_player_unit.setExp(chosen_player_unit.getExp() + chosen_player_unit.getStrength());
        unit_to_hit.setHp(unit_to_hit.getHp() - received_damage);
        cout << unit_to_hit.getName() << " got damage: " << received_damage<< '\n';
        log = unit_to_hit.getName() + " got damage: " + ::to_string(received_damage) + '\n';
    }
    if(player_ulti.getName() == "evasion"){
        chosen_player_unit.setAgility(chosen_player_unit.getAgility() + player_ulti.getDamage());
        log = chosen_player_unit.getName() + " agility was increased by (" +  ::to_string(player_ulti.getDamage()) + ")\n";
    }

    if(player_ulti.getName() == "berserk_mode"){
        chosen_player_unit.setAgility(chosen_player_unit.getStrength() + player_ulti.getDamage());
        log = chosen_player_unit.getName() + " strength was increased by (" +  ::to_string(player_ulti.getDamage()) + ")\n";
    }
    if(player_ulti.getName() == "heal"){
        return GameLogic::heal(unit_to_hit, chosen_player_unit);
    }
    chosen_player_unit.getSuperPower().setIsUsed(true);
    return log;
}

string GameLogic::heal(Unit &unit_to_heal, Unit &chosen_unit){
    unit_to_heal.setHp(unit_to_heal.getHp() + chosen_unit.getSuperPower().getDamage());
    return unit_to_heal.getName() + " hp was increased by (" + ::to_string(chosen_unit.getSuperPower().getDamage()) + ")\n";
}

string GameLogic::earthquake(Unit &chosen_unit, vector<Unit> &enemy_pick) {
    string log;
    for(auto & i : enemy_pick){
        i.setHp(i.getHp()-chosen_unit.getSuperPower().getDamage());
        string temp_log = i.getName() + " got damage (" + ::to_string(chosen_unit.getSuperPower().getDamage()) + ")\n";
        log += temp_log;
    }
    chosen_unit.getSuperPower().setIsUsed(true);
    return log;
}

