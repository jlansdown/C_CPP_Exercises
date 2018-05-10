//
// Created by James Lansdown on 5/9/18.
//

#include "Ship.h"
#include <iostream>

Ship::Ship() : name(""), year("") {
}

Ship::Ship(string shipName, string yearBuilt) {
    name = shipName;
    year = yearBuilt;
}

void Ship::setName(string shipName) {
    name = shipName;
}

string Ship::getName() {
    return name;
}

void Ship::setYear(string yearBuilt) {
    year = yearBuilt;
}

string Ship::getYear() {
    return year;
}

void Ship::print() {
    cout << "Ship name: " << name
         << "\nYear built: " << year << endl;
}
