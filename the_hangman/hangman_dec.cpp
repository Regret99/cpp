#include "hangman_dec.h"
#include <iostream>
#include <vector>


void greet(std::string name) {
    std::cout<< "Welcome, " << name << std::endl;
}

void welcome() {
    std::cout << std::endl;
    std::cout << "Welcome to The Hangman Game" << std::endl;
}

void drawLetters(const std::vector<char>& guessedWord) {
    std::cout << "Guess the correct letters to save the Man" << std::endl;
    std::cout << std::endl;
    for (char c : guessedWord) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
}

void drawHangman(int miss = 0) {
    if (miss == 0) {

        std::cout << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << std::endl;
        std::cout << "      *--------*          " << std::endl;
        std::cout << "      |        |          " << std::endl;
        std::cout << "               |          " << std::endl;
        std::cout << "               |          " << std::endl;
        std::cout << "               |          " << std::endl;
        std::cout << "               |          " << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << std::endl;
    }
    if (miss == 1) {

        std::cout << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << std::endl;
        std::cout << "      *--------*          " << std::endl;
        std::cout << "      |        |          " << std::endl;
        std::cout << "      O        |          " << std::endl;
        std::cout << "               |          " << std::endl;
        std::cout << "               |          " << std::endl;
        std::cout << "               |          " << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << std::endl;
        std::cout << "Got the Head" << std::endl;

    }
    if (miss == 2) {

        std::cout << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << std::endl;
        std::cout << "      *--------*          " << std::endl;
        std::cout << "      |        |          " << std::endl;
        std::cout << "      O        |          " << std::endl;
        std::cout << "      |        |          " << std::endl;
        std::cout << "               |          " << std::endl;
        std::cout << "               |          " << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << std::endl;
        std::cout << "Got the Body" << std::endl;

    }
    if (miss == 3) {

        std::cout << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << std::endl;
        std::cout << "      *--------*          " << std::endl;
        std::cout << "      |        |          " << std::endl;
        std::cout << "      O        |          " << std::endl;
        std::cout << "     /|        |          " << std::endl;
        std::cout << "               |          " << std::endl;
        std::cout << "               |          " << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << std::endl;
        std::cout << "Got the Left Arm" << std::endl;

    }
    if (miss == 4) {

        std::cout << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << std::endl;
        std::cout << "      *--------*          " << std::endl;
        std::cout << "      |        |          " << std::endl;
        std::cout << "      O        |          " << std::endl;
        std::cout << "     /|\\       |          " << std::endl;
        std::cout << "               |          " << std::endl;
        std::cout << "               |          " << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << std::endl;
        std::cout << "Got the Right Arm" << std::endl;

    }
    if (miss == 5) {

        std::cout << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << std::endl;
        std::cout << "      *--------*          " << std::endl;
        std::cout << "      |        |          " << std::endl;
        std::cout << "      O        |          " << std::endl;
        std::cout << "     /|\\       |          " << std::endl;
        std::cout << "     /         |          " << std::endl;
        std::cout << "               |          " << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << std::endl;
        std::cout << "Got the Left Leg" << std::endl;

    }
    if (miss == 6) {

        std::cout << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << std::endl;
        std::cout << "      *--------*          " << std::endl;
        std::cout << "      |        |          " << std::endl;
        std::cout << "      O        |          " << std::endl;
        std::cout << "     /|\\       |          " << std::endl;
        std::cout << "     / \\       |          " << std::endl;
        std::cout << "               |          " << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << std::endl;
        std::cout << "Got the Right Leg" << std::endl;

    }
    std::cout << std::endl;
    std::cout << std::endl;
}