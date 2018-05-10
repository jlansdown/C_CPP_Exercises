//
// Created by James Lansdown on 5/9/18.
//
#include <string>
using namespace std;

#ifndef HOMEWORK_4_PARKEDCAR_H
#define HOMEWORK_4_PARKEDCAR_H


class ParkedCar {

private:
    string make;
    string model;
    string color;
    string license;
    double timeParked;


public:
    ParkedCar();
    ParkedCar(string mke, string mdl, string colr, string lP, double time);

    string getMake();
    string getModel();
    string getColor();
    string getLicense();
    double getTimeParked();

};



#endif //HOMEWORK_4_PARKEDCAR_H
