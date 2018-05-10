//
// Created by James Lansdown on 5/9/18.
//

#ifndef HOMEWORK_4_CRUISESHIP_H
#define HOMEWORK_4_CRUISESHIP_H

#include "Ship.h"
#include <string>

using namespace std;

class CruiseShip : public Ship {

private:
    int passengers;

public:
    CruiseShip();
    CruiseShip(string shipName, string yearBuilt, int pass);

    void setPassengers(int pass);
    int getPassengers();

    void print() override;
};


#endif //HOMEWORK_4_CRUISESHIP_H
