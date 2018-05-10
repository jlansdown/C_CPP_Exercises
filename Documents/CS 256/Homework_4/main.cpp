#include <iostream>
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include "PoliceOfficer.h"
#include "Game21.h"
#include "Ship.h"
#include "CruiseShip.h"
#include "CargoShip.h"



using namespace std;

int main() {

    //21 Game Object
    Game21 game;

    //Parking Simulator Objects
    ParkedCar car("Toyota", "Corolla", "Panda", "4age20v", 3);
    ParkingMeter meter(1);
    PoliceOfficer officer("Joe Muster", 15426);

    ParkingTicket ticket;
    ticket = officer.ticket(car, meter);

    //Ship Objects
    const int NUM_SHIPS = 3;
    Ship *ships[NUM_SHIPS] = {
            new Ship("Little boat", "2001"),
            new CruiseShip("Titanic", "1944", 20000),
            new CargoShip("Beast", "1911", 2500)
    };

    int selection = 0, exit = 0;

    do {
        cout << "\n1) Play 21\n2) Parking \n3) Ships \n4) Finish\nSelection: ";


         do {
             if (cin >> selection) {
                 break;
             } else {
                 cout << "Please enter a valid integer: ";
                 cin.clear();
                 cin.ignore(numeric_limits<streamsize>::max(), '\n');
             }
        }while (!isdigit(selection));

        switch (selection) {
            case 1:
                game.play();
                game.reset();
                break;

            case 2:
                cout << ticket.reportCar(car) << endl;
                cout << ticket.reportOfficer(officer) << endl;
                cout << "Fine: $" << ticket.reportFine(car, meter) << endl;
                break;

            case 3:
                cout << endl;
                for (int i = 0; i < NUM_SHIPS; i++) {
                    ships[i]->print();
                    cout << endl;
                }
                break;

            case 4:
                exit = 4;
                break;

            default:
                cout << "Invalid selection" << endl;
                break;
        }
    }while (exit != 4);

    return 0;
}