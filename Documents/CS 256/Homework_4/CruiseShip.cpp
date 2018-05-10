//
// Created by James Lansdown on 5/9/18.
//

#include "CruiseShip.h"
#include <iostream>



CruiseShip::CruiseShip() : passengers(0) {
    setName("");
    setYear("");
}

CruiseShip::CruiseShip(string shipName, string yearBuilt, int pass) {
    setName(shipName);
    setYear(yearBuilt);
    passengers = pass;
}

void CruiseShip::setPassengers(int pass) {
    passengers = pass;
}

int CruiseShip::getPassengers() {
    return passengers;
}

void CruiseShip::print() {
    cout << "Ship name: " << this->getName()
         << "\nYear built: " << this->getYear() << endl
         << "Passengers: " << passengers << endl;
}
