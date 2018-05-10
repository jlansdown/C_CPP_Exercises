#include "PoliceOfficer.h"


PoliceOfficer::PoliceOfficer() : name(""), badgeNumber(0) {
}

PoliceOfficer::PoliceOfficer(string nme, int bdgNum) {
    name = nme;
    badgeNumber = bdgNum;
}

ParkingTicket PoliceOfficer::ticket(ParkedCar& car, ParkingMeter& meter) {

    ParkingTicket ticket;
        //if (car.getTimeParked() > meter.getTimePurchased()) {
            return ticket;
       // }
}

int PoliceOfficer::getBadge() {
    return badgeNumber;
}

string PoliceOfficer::getName() {
    return name;
}
