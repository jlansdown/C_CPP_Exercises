#ifndef HOMEWORK_4_SHIP_H
#define HOMEWORK_4_SHIP_H

#include <string>

using namespace std;

class Ship {

private:
    string name;
    string year;

public:
    Ship();
    Ship(string shipName, string yearBuilt);

    void setName(string shipName);
    string getName();

    void setYear(string yearBuilt);
    string getYear();

    virtual void print();
};

#endif //HOMEWORK_4_SHIP_H
