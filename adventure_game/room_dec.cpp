#include "room_dec.h"
#include <iostream>
#include <vector>
#include "utils.h"
#include "story_item.h"



void greet(std::string name) {
    std::cout<< "Welcome, " << name << std::endl;
}

void foyerChoice() {

    StoryItem* enterFoyer = new StoryItem();

    // typeText("You looked around and saw that you are in a straight hallway");
    // typeText("You see stairs leading to ground floor in the front");
    // typeText("You see couple of rooms on your left which seemed locked");

    enterFoyer->preText = "You looked around and saw that you are in a straight hallway. \n"
                          "You see stairs leading to ground floor in the front. \n"
                          "You see couple of rooms on your left which seemed locked. \n";
    enterFoyer->preTextColour = "magenta";

    enterFoyer->prompt = "What will you do?";

    enterFoyer->options = {
        "Go to the ground floor.", // 1
        "Try opening the locked rooms.", // 2
    };

    int choice = enterFoyer->run();

    if (choice == 1) {
        printInColor("\nYou die.", "red");
    } else if (choice == 2) {
        // explore_new_planet();
    } else if (choice == 3) {
        printInColor("\nyou starved to death", "red");
    }



}