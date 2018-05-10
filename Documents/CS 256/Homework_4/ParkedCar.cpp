//
// Created by James Lansdown on 5/9/18.
//

#include "ParkedCar.h"

ParkedCar::ParkedCar() : make(""), model(""),
                         color(""), license(""), timeParked(0) {
}

ParkedCar::ParkedCar(string mke, string mdl, string colr, string lP, double time) :
        make(mke), model(mdl), color(colr), license(lP), timeParked(time) {
}

string ParkedCar::getMake() {
    return make;
}

string ParkedCar::getModel() {
    return model;
}

string ParkedCar::getColor() {
    return color;
}

string ParkedCar::getLicense() {
    return license;
}

double ParkedCar::getTimeParked() {
    return timeParked;
}

