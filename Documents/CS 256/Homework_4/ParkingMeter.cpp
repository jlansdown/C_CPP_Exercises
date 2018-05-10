//
// Created by James Lansdown on 5/9/18.
//

#include "ParkingMeter.h"

ParkingMeter::ParkingMeter() : timePurchased(0) {
}

ParkingMeter::ParkingMeter(double tP) {
    timePurchased = tP;
}

double ParkingMeter::getTimePurchased() {
    return timePurchased;
}