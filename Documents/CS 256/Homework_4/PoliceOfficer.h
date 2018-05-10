using namespace std;

#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"

#ifndef HOMEWORK_4_POLICEOFFICER_H
#define HOMEWORK_4_POLICEOFFICER_H

class PoliceOfficer {

private:
    string name;
    int badgeNumber;

    friend class ParkingTicket;

public:
    PoliceOfficer();
    PoliceOfficer(string nme, int bdgNum);
    ParkingTicket ticket(ParkedCar& car, ParkingMeter& meter);
    string getName();
    int getBadge();

};


#endif //HOMEWORK_4_POLICEOFFICER_H
