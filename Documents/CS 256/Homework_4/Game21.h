
#ifndef HOMEWORK_4_GAME21_H
#define HOMEWORK_4_GAME21_H

#include "Die.h"

class Game21 {

private :
    int playerScore;
    int compScore;
    Die die;

public:

    Game21();

    void play();
    void reset();

};


#endif //HOMEWORK_4_GAME21_H
