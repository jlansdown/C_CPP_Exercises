//
// Created by James Lansdown on 5/9/18.
//
#include "ParkingTicket.h"
#include "PoliceOfficer.h"
#include <cmath>


ParkingTicket::ParkingTicket() : initialFine(25.00), extraFine(10.00) {
}


string ParkingTicket::reportCar(ParkedCar& car) {
    return "\nCar make: " + car.getMake() +
           "\nCar model: " + car.getModel() +
           "\nCar color: " + car.getColor() +
           "\nCar license number: " + car.getLicense();
}


double ParkingTicket::reportFine(ParkedCar& car, ParkingMeter& meter) {
    double totalFine = 0;
    double overTime = 0;

    if (car.getTimeParked() > meter.getTimePurchased()) {
        totalFine = initialFine;
        overTime = ceil((car.getTimeParked() - meter.getTimePurchased())) * extraFine;
    }

    return totalFine + overTime;
}

string ParkingTicket::reportOfficer(PoliceOfficer& officer) {

    string name = officer.name;
    string badge = to_string(officer.badgeNumber);

    return "Officer name: " + name + "\nBadge #: " + badge;
}