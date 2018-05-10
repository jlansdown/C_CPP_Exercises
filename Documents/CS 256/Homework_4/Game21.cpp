//
// Created by James Lansdown on 5/9/18.
//

#include "Game21.h"
#include <iostream>

using namespace std;

Game21::Game21() : playerScore(0), compScore(0) {
}

void Game21::play() {

    int exit = 0;
    int selection;
    bool playerExit = false;



    do {

        if (compScore < 22) {
            this->die.roll();
            this->compScore += die.getValue();
            this->die.roll();
            this->compScore += die.getValue();
        }

        cout << "Player score: " << playerScore <<
             "\n\nRoll: 1)\nFinish: 2)\nSelection: ";
        cin >> selection;

        switch (selection) {
            case 1:
                this->die.roll();
                this->playerScore += die.getValue();
                this->die.roll();
                this->playerScore += die.getValue();

                break;

            case 2:
                exit = 2;
                playerExit = true;
                break;
        }

        if (playerScore > 21) {
            cout << endl << "Computer Wins!!!";
            exit = 2;
        } else if (compScore > 21) {
            cout << endl << "Player Wins!!!";
            exit = 2;
        }
    } while (exit != 2);

    if (playerExit) {
        if (playerScore > compScore && playerScore < 22) {
            cout << endl << "Player Wins!!!";
        } else if (compScore > playerScore && compScore < 22) {
            cout << endl << "Computer Wins!!!";
        }
    }

    if (playerScore == compScore) {
        cout << "Tie!!!";
    }

    cout << endl << "Player score: " << playerScore << endl;
    cout << "Computer score: " << compScore << endl;

}

void Game21::reset() {
    playerScore = 0;
    compScore = 0;
}