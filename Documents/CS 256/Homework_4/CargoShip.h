#ifndef HOMEWORK_4_CARGOSHIP_H
#define HOMEWORK_4_CARGOSHIP_H

#include "Ship.h"

class CargoShip : public Ship {

private:
    int tonnage;

public:
    CargoShip();
    CargoShip(string shipName, string yearBuilt, int tons);

    void setTonnage(int tons);
    int getTonnage();

    void print() override;
};

#endif //HOMEWORK_4_CARGOSHIP_H
