//
// Created by 48724 on 17.06.2022.
//

#include "Units_Pool.h"

void Units_Pool::fillTheVector() {
    auto *temp_super_power = new Super_power("ball", 12);
    Unit *temp_unit = new Unit("Water Archer", "water", 4, 6, 13, 0, *temp_super_power, "COMMON");
    units.push_back(*temp_unit);

    *temp_super_power = *new Super_power("ball", 12);
    *temp_unit = *new Unit("Fire Archer", "fire", 4, 6, 15, 0, *temp_super_power, "COMMON");
    units.push_back(*temp_unit);

    *temp_super_power = *new Super_power("ball", 12);
    *temp_unit = *new Unit("Wind Archer", "wind", 4, 6, 15, 0, *temp_super_power, "COMMON");
    units.push_back(*temp_unit);

    *temp_super_power = *new Super_power("berserk_mode", 5);
    *temp_unit = *new Unit("Ground Spearman", "wind", 3, 5, 20, 0, *temp_super_power, "COMMON");
    units.push_back(*temp_unit);

    *temp_super_power = *new Super_power("berserk_mode", 5);
    *temp_unit = *new Unit("Ice Spearman", "ice", 3, 5, 20, 0, *temp_super_power, "COMMON");
    units.push_back(*temp_unit);

    *temp_super_power = *new Super_power("berserk_mode", 5);
    *temp_unit = *new Unit("Metal Spearman", "metal", 3, 5, 20, 0, *temp_super_power, "RARE");
    units.push_back(*temp_unit);

    *temp_super_power = *new Super_power("evasion", 5);
    *temp_unit = *new Unit("Water Assassin", "water", 4, 8, 15, 0, *temp_super_power, "RARE");
    units.push_back(*temp_unit);

    *temp_super_power = *new Super_power("evasion", 5);
    *temp_unit = *new Unit("Fire Assassin", "fire", 4, 8, 15, 0, *temp_super_power, "RARE");
    units.push_back(*temp_unit);

    *temp_super_power = *new Super_power("evasion", 5);
    *temp_unit = *new Unit("Ice Assassin", "ice", 4, 8, 15, 0, *temp_super_power, "RARE");
    units.push_back(*temp_unit);

    *temp_super_power = *new Super_power("ball", 15);
    *temp_unit = *new Unit("Griffin", "fire", 2, 6, 25, 0, *temp_super_power, "RARE");
    units.push_back(*temp_unit);

    *temp_super_power = *new Super_power("heal", 15);
    *temp_unit = *new Unit("ANGEL", "wind", 1, 4, 30, 0, *temp_super_power, "IMMORTAL");
    units.push_back(*temp_unit);

    *temp_super_power = *new Super_power("strike", 25);
    *temp_unit = *new Unit("ICE DRAGON", "ice", 4, 10, 28, 0, *temp_super_power, "IMMORTAL");
    units.push_back(*temp_unit);

    *temp_super_power = *new Super_power("strike", 25);
    *temp_unit = *new Unit("FIRE DRAGON", "fire", 4, 10, 28, 0, *temp_super_power, "IMMORTAL");
    units.push_back(*temp_unit);

    *temp_super_power = *new Super_power("strike", 25);
    *temp_unit = *new Unit("WATER DRAGON", "water", 4, 10, 28, 0, *temp_super_power, "IMMORTAL");
    units.push_back(*temp_unit);

    *temp_super_power = *new Super_power("earthquake", 6);
    *temp_unit = *new Unit("GIANT", "metal", 2, 5, 37, 0, *temp_super_power, "IMMORTAL");
    units.push_back(*temp_unit);
}

Units_Pool::Units_Pool() {
    fillTheVector();
}

void Units_Pool::printUnitsPool(vector<Unit> vector) {
    cout << "-----------------------------\n";
    for (int i = 0; i < vector.size(); i++) {
        cout << "UNIT #" << i + 1 << endl;
        cout << vector.at(i).to_string();
    }
}

vector<Unit> Units_Pool::filter_vector(const string &type) {
    vector<Unit> result_vector;
    for (auto &unit: units) {
        if (unit.getType() == type) {
            result_vector.push_back(unit);
        }
    }
    return result_vector;
}
