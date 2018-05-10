//
// Created by James Lansdown on 5/9/18.
//

#ifndef HOMEWORK_4_DIE_H
#define HOMEWORK_4_DIE_H


class Die {

private:
    int sides;
    int value;

public:
    explicit Die(int = 6);
    void roll();
    int getSides();
    int getValue();

};


#endif //HOMEWORK_4_DIE_H
