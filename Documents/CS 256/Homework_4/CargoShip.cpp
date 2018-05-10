//
// Created by James Lansdown on 5/10/18.
//

#include "CargoShip.h"
#include <iostream>

CargoShip::CargoShip() : tonnage(0) {
    this->setName("");
    this->setYear("");
}

CargoShip::CargoShip(string shipName, string yearBuilt, int tons) {
    this->setName(shipName);
    this->setYear(yearBuilt);
    tonnage = tons;
}

void CargoShip::setTonnage(int tons) {
    tonnage = tons;
}

int CargoShip::getTonnage() {
    return tonnage;
}

void CargoShip::print() {
    cout << "Ship name: " << this->getName()
         << "\nYear built: " << this->getYear() << endl
         << "Tonnage: " << tonnage << endl;
}
