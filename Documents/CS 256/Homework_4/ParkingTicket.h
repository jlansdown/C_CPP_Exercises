//
// Created by James Lansdown on 5/9/18.
//

#include <iostream>
#include "ParkedCar.h"
#include "ParkingMeter.h"


class PoliceOfficer;

using namespace std;

#ifndef HOMEWORK_4_PARKINGTICKET_H
#define HOMEWORK_4_PARKINGTICKET_H

class ParkingTicket {

private:
    double initialFine;
    double extraFine;

public:
    ParkingTicket();


    string reportCar(ParkedCar& car);
    double reportFine(ParkedCar& car, ParkingMeter& meter);
    string reportOfficer(PoliceOfficer& officer);

};

#endif //HOMEWORK_4_PARKINGTICKET_H
