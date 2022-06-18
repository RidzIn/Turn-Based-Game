//
// Created by 48724 on 17.06.2022.
//

#ifndef PASSWORDS_MANAGER_UNITS_POOL_H
#define PASSWORDS_MANAGER_UNITS_POOL_H

#include "Unit.h"

class Units_Pool {
private:
    vector<Unit> units;

    void fillTheVector();

public:
    Units_Pool();


    vector<Unit> filter_vector(const string &type);

    static void printUnitsPool(vector<Unit> vector);
};


#endif //PASSWORDS_MANAGER_UNITS_POOL_H
