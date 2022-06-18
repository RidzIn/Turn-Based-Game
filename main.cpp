#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include "Super_power.h"
#include "Unit.h"
#include "Units_Pool.h"
#include "GameLogic.h"
#include <random>

using namespace std;

int main(int argc, char **argv) {

    if (strcmp(argv[1], "--help") == 0) {
        GameLogic::print_game_manual();
    }

    //creating player_pick and enemy_pick vectors
    auto *unitsPool = new Units_Pool;
    vector<Unit> player_pick;
    vector<Unit> enemy_pick;

    // generate log file
    std::ofstream out;
    out.open(R"(C:\Users\48724\CLionProjects\passwords_manager\logs)", std::ofstream::trunc);

    // starting the game loop
    while (true) {
        cout << "Welcome to my turn based game.\n";
        cout << "Press (1) to see units you can pick\n";
        cout << "Press (2) to get out the game\n";
        int menu;
        cin >> menu;
        if (menu == 1) {
            int select_difficulty;
            cout << "Select difficulty\n";
            cout << "(1) - pussy mode:(4 enemy's on the bord: 3 common, 1 rare)\n";
            cout << "(2) - normal mode:(5 enemy's on the bord: 3 common, 1 rare, 1 immortal)\n";
            cout << "(3) - \'Welcome To Hell\' mode:(6 enemy's on the bord: 2 common, 2 rare, 2 immortal)\n";
            while (true) {
                cin >> select_difficulty;
                if (select_difficulty == 1) {
                    cout << "Disappointed in you. You choose pussy mode!\n";
                    break;
                }
                if (select_difficulty == 2) {
                    cout << "I wish you choose 3, but anyway!\n";
                    break;
                }
                if (select_difficulty == 3) {
                    cout << "You like suffering, don't you?\n";
                    break;
                }
                GameLogic::incorrect_number(1, 3);

            }
            cout << "Now let's pick 6 units.(3 common, 2 rare, 1 immortal)\n";
            int index_unit_to_add;
            while (player_pick.size() != 3) {
                cout << "Pick 3 common units\n";
                vector<Unit> common_vector = unitsPool->filter_vector("COMMON");
                Units_Pool::printUnitsPool(common_vector);
                cin >> index_unit_to_add;
                if (index_unit_to_add < 1 || index_unit_to_add > common_vector.size()) {
                    GameLogic::incorrect_number(1, (int) common_vector.size());
                    continue;
                }
                player_pick.push_back(common_vector.at(index_unit_to_add - 1));

            }
            while (player_pick.size() != 5) {
                cout << "Pick 2 rare units\n";
                vector<Unit> rare_vector = unitsPool->filter_vector("RARE");
                Units_Pool::printUnitsPool(rare_vector);
                cin >> index_unit_to_add;
                if (index_unit_to_add < 1 || index_unit_to_add > rare_vector.size()) {
                    GameLogic::incorrect_number(1, (int) rare_vector.size());
                    continue;
                }
                player_pick.push_back(rare_vector.at(index_unit_to_add - 1));
            }
            while (player_pick.size() != 6) {
                cout << "Pick 1 immortal unit\n";
                vector<Unit> immortal_vector = unitsPool->filter_vector("IMMORTAL");
                Units_Pool::printUnitsPool(immortal_vector);
                cin >> index_unit_to_add;
                if (index_unit_to_add < 1 || index_unit_to_add > immortal_vector.size()) {
                    GameLogic::incorrect_number(1, (int) immortal_vector.size());
                    continue;
                }
                player_pick.push_back(immortal_vector.at(index_unit_to_add - 1));
            }
            if (out.is_open()) {
                out << "\t\t\t\t\t\t\t YOUR PICK\n";
                for (auto &i: player_pick) {
                    out << i.to_string();
                }
            }
            out.close();
            cout << "Now generated enemy pick\n";
            std::random_device random_device; // create object for seeding
            std::mt19937 engine{random_device()}; // create engine and seed it
            switch (select_difficulty) {
                case 1:
                    for (int i = 0; i < 3; i++) {
                        std::uniform_int_distribution<> dist(0,(int)unitsPool->filter_vector("COMMON").size()-1);
                        int random_index = dist(engine);
                        enemy_pick.push_back(unitsPool->filter_vector("COMMON").at(random_index));
                    }
                    for (int i = 0; i < 1; i++) {
                        std::uniform_int_distribution<> dist(0,(int)unitsPool->filter_vector("COMMON").size()-1);
                        int random_index = dist(engine);
                        enemy_pick.push_back(unitsPool->filter_vector("RARE").at(random_index));
                    }
                    break;
                case 2:
                    for (int i = 0; i < 3; i++) {
                        std::uniform_int_distribution<> dist(0,(int)unitsPool->filter_vector("COMMON").size()-1);
                        int random_index = dist(engine);
                        enemy_pick.push_back(unitsPool->filter_vector("COMMON").at(random_index));
                    }
                    for (int i = 0; i < 1; i++) {
                        std::uniform_int_distribution<> dist(0,(int)unitsPool->filter_vector("RARE").size()-1);
                        int random_index = dist(engine);
                        enemy_pick.push_back(unitsPool->filter_vector("RARE").at(random_index));
                    }
                    for (int i = 0; i < 1; i++) {
                        std::uniform_int_distribution<> dist(0,(int)unitsPool->filter_vector("IMMORTAL").size()-1);
                        int random_index = dist(engine);
                        enemy_pick.push_back(unitsPool->filter_vector("IMMORTAL").at(random_index));
                    }
                    break;
                case 3:
                    for (int i = 0; i < 2; i++) {
                        std::uniform_int_distribution<> dist(0,(int)unitsPool->filter_vector("COMMON").size()-1);
                        int random_index = dist(engine);
                        enemy_pick.push_back(unitsPool->filter_vector("COMMON").at(random_index));
                    }
                    for (int i = 0; i < 2; i++) {
                        std::uniform_int_distribution<> dist(0,(int)unitsPool->filter_vector("RARE").size()-1);
                        int random_index = dist(engine);
                        enemy_pick.push_back(unitsPool->filter_vector("RARE").at(random_index));
                    }
                    for (int i = 0; i < 2; i++) {
                        std::uniform_int_distribution<> dist(0,(int)unitsPool->filter_vector("IMMORTAL").size()-1);
                        int random_index = dist(engine);
                        enemy_pick.push_back(unitsPool->filter_vector("IMMORTAL").at(random_index));
                    }
                    break;
                default:
                    break;
            }
            out.open(R"(C:\Users\48724\CLionProjects\passwords_manager\logs)", std::ios::app);
            if (out.is_open()) {
                out << "\t\t\t\t\t\t\t Enemy Pick\n";
                for (auto &i: enemy_pick) {
                    out << i.to_string();
                }
            }
            out.close();

            // starting the fight
            int turn_to_move = 0;
            int step = 1;
            while (true) {
                out.open(R"(C:\Users\48724\CLionProjects\passwords_manager\logs)", std::ios::app);
                if (player_pick.size() == 1 && player_pick.at(0).getHp() <= 0) {
                    out << "\t\t\t************************\n";
                    out << "\t\t\t*******COMPUTER WON*****\n";
                    out << "\t\t\t************************\n";
                    return GameLogic::end_the_game();
                }
                if (enemy_pick.size() == 1 && enemy_pick.at(0).getHp() <= 0) {
                    out << "\t\t\t************************\n";
                    out << "\t\t\t*******PLAYER WON*******\n";
                    out << "\t\t\t************************\n";

                    return GameLogic::end_the_game();
                }
                if (out.is_open()) {
                    out << "\t\t\t\t\t\t STEP: " << step << '\n';
                }
                step++;
                if (turn_to_move % 2 == 0) {
                    int current_unit;
                    while (true) {
                        cout << "\t\t\t\t\tPlayer turn to move\n";
                        cout << "Choose your unit\n";
                        GameLogic::displayUnits(player_pick);
                        cin >> current_unit;
                        if (current_unit > player_pick.size() || current_unit < 1) {
                            GameLogic::incorrect_number(1, (int) player_pick.size());
                            continue;
                        } else {
                            int option;
                            while (true) {
                                cout << "You have 4 options\n";
                                cout << "(1) Hit\n";
                                cout << "(2) Use Super Power\n";
                                cout << "(3) Switch\n";
                                cout << "(4) Upgrade\n";
                                cout << "(5) End the game\n";
                                cin >> option;
                                if (option > 5 || option < 1) {
                                    GameLogic::incorrect_number(1, 5);
                                    continue;
                                } else {
                                    switch (option) {
                                        case 1:
                                            while (true) {
                                                int target;
                                                cout << "Select the enemy unit which you want to hit\n";
                                                GameLogic::displayUnits(enemy_pick);
                                                cin >> target;
                                                if (target > enemy_pick.size() || target < 1) {
                                                    continue;
                                                }
                                                target--;
                                                if (enemy_pick.at(target).isDead()) {
                                                    enemy_pick.erase(enemy_pick.begin() + target);
                                                    cout
                                                            << "This unit is already dead\n"; // use check in case if you delete the unit
                                                    continue;
                                                }
                                                out << GameLogic::player_hit(player_pick.at(current_unit - 1),
                                                                             enemy_pick.at(target), "PLAYER");
                                                break;
                                            }
                                            break;
                                        case 2:
                                            while (true) {
                                                string super_power_name = player_pick.at(
                                                        current_unit - 1).getSuperPower().getName();
                                                int target;
                                                if (super_power_name == "heal") {
                                                    cout << "Select unit which you want to heal\n";
                                                    cout << GameLogic::displayUnits(player_pick);
                                                    cin >> target;
                                                    if (target > player_pick.size() || target < 1) {
                                                        GameLogic::incorrect_number(1, (int)player_pick.size());
                                                        continue;
                                                    }
                                                    out << GameLogic::use_ultimate(player_pick.at(current_unit - 1),
                                                                                   player_pick.at(target - 1),
                                                                                   "PLAYER");
                                                    break;
                                                }
                                                if (super_power_name == "evasion" ||
                                                    super_power_name == "berserk_mode") {
                                                    out << GameLogic::use_ultimate(player_pick.at(current_unit - 1),
                                                                                   enemy_pick.at(0), "PLAYER");
                                                    break;
                                                }
                                                if (super_power_name == "earthquake") {
                                                    out << GameLogic::earthquake(player_pick.at(current_unit - 1),
                                                                                 enemy_pick);
                                                    break;
                                                }
                                                cout << "Select the enemy unit which you want to hit\n";
                                                GameLogic::displayUnits(enemy_pick);
                                                cin >> target;
                                                if (target > enemy_pick.size() || target < 1) {
                                                    continue;
                                                }
                                                target--;
                                                if (enemy_pick.at(target).isDead()) {
                                                    enemy_pick.erase(enemy_pick.begin() + target);
                                                    cout
                                                            << "This unit is already dead\n"; // use check in case if you delete the unit
                                                    continue;
                                                }
                                                out << GameLogic::use_ultimate(player_pick.at(current_unit - 1),
                                                                               enemy_pick.at(target), "PLAYER");
                                                break;
                                            }
                                            break;
                                        case 3:
                                            while (true) {
                                                cout << "Select the unit to switch and hit\n";
                                                GameLogic::displayUnits(player_pick);
                                                cin >> current_unit;
                                                if (current_unit < 1 || current_unit > player_pick.size()) {
                                                    continue;
                                                }
                                                while (true) {
                                                    int target;
                                                    cout << "Select the enemy unit which you want to hit\n";
                                                    GameLogic::displayUnits(enemy_pick);
                                                    cin >> target;
                                                    if (target < 1 || target > enemy_pick.size()) {
                                                        continue;
                                                    }
                                                    target--;
                                                    out << GameLogic::player_hit(player_pick.at(current_unit - 1),
                                                                                 enemy_pick.at(target), "PLAYER");
                                                    break;
                                                }
                                                break;
                                            }
                                            break;
                                        case 4:
                                            while (true) {
                                                if (player_pick.at(current_unit - 1).getExp() > 20) {
                                                    int power_up;
                                                    cout << "Select attribute which you want to power up\n";
                                                    cout << "(1) to power up agility\n";
                                                    cout << "(2) to power up strength\n";
                                                    cin >> power_up;
                                                    if (power_up > 2 || power_up < 1) {
                                                        continue;
                                                    }
                                                    if (power_up == 1) {
                                                        player_pick.at(current_unit - 1).setAgility(
                                                                player_pick.at(current_unit - 1).getAgility() + 1);
                                                        out << player_pick.at(current_unit - 1).getName() +
                                                               " increased agility\n";
                                                        player_pick.at(current_unit - 1).setExp(
                                                                player_pick.at(current_unit - 1).getExp() - 20);
                                                    }
                                                    if (power_up == 2) {
                                                        player_pick.at(current_unit - 1).setStrength(
                                                                player_pick.at(current_unit - 1).getStrength() + 1);
                                                        out << player_pick.at(current_unit - 1).getName() +
                                                               " increased strength\n";
                                                        player_pick.at(current_unit - 1).setExp(
                                                                player_pick.at(current_unit - 1).getExp() - 20);
                                                    }
                                                } else {
                                                    cout << player_pick.at(current_unit - 1).getName()
                                                         << " does not have enough exp to power up\n";
                                                }
                                                break;
                                            }
                                            break;
                                        case 5:
                                            return GameLogic::end_the_game();
                                        default:
                                            break;
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    }
                } else {
                    cout << "Enemy turn to move\n";
                    cout << "Player size: " << player_pick.size() << endl;
                    cout << "Enemy size: " << enemy_pick.size() << endl;
                    out << GameLogic::enemyAI(player_pick, enemy_pick, "COMPUTER");
                }
                out << "\t\t\t\tPLAYER STATUS\n";
                out << GameLogic::displayUnits(player_pick);
                out << "\t\t\t\tENEMY STATUS\n";
                out << GameLogic::displayUnits(enemy_pick);
                turn_to_move++;

                out.close();
            }
        }
        if (menu == 2) {
            GameLogic::end_the_game();
            return 0;
        }
        else {
            GameLogic::incorrect_number(1, 2);
            continue;
        }
    }
}
