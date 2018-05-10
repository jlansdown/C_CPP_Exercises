//
// Created by James Lansdown on 5/9/18.
//

#ifndef HOMEWORK_4_PARKINGMETER_H
#define HOMEWORK_4_PARKINGMETER_H

class ParkingMeter {

private:
    double timePurchased;

    friend class PoliceOfficer;
    friend class ParkingTicket;

public:
    ParkingMeter();
    explicit ParkingMeter(double tP);

    double getTimePurchased();
};





#endif //HOMEWORK_4_PARKINGMETER_H
