#include "room_dec.h"
#include <iostream>
#include <vector>
#include "utils.h"



void greet(std::string name) {
    std::cout<< "Welcome, " << name << std::endl;
}

void foyerChoice() {
    typeText("You looked around and saw that you are in a straight hallway");
    typeText("You see stairs leading to ground floor in the front");
    typeText("You see couple of rooms on your left which seemed locked");
}