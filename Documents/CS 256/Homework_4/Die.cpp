
#include "Die.h"
#include <cmath>
#include <iostream>

Die::Die(int numSides) {

    auto seed = (unsigned)time(NULL);

    srand(seed);

    sides = numSides;
    roll();
}

void Die::roll() {

    const int MIN_VALUE = 1;

    value = (rand() % (sides - MIN_VALUE + 1)) + MIN_VALUE;
}


int Die::getSides() {
    return sides;
}

int Die::getValue() {
    return value;
}