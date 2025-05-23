#include "room_dec.h"
#include <iostream>
#include <vector>
#include "utils.h"
#include "story_item.h"



void greet(std::string name) {
    std::cout<< "Welcome, " << name << std::endl;
}

// void intro() {
//     StoryItem* enterFoyer = new StoryItem();

// }

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
        "Go Back Inside?", // 3
    };

    int choice = enterFoyer->run();

    if (choice == 1) {
        groundFloor();
        // printInColor("\nYou died.", "red");

    } else if (choice == 2) {
        printInColor("\nYou tried all doors but they all are locked\n");
        foyerChoice();
    } else if (choice == 3) {
        printInColor("\nyou starved to death", "red");
    }
}

void groundFloor() {
    StoryItem* groundFloor = new StoryItem();

    groundFloor->preText = "\nOn the ground floor you see a big corridor.\n"
                           "There are doors to various rooms like Kitchen, Study\n";
    groundFloor->preTextColour = "magenta";

    groundFloor->options = {
        "Check Study",
        "Check Washroom",
        "Checkout Kitchen",
    };

    int choice = groundFloor->run();


    if (choice == 1) {
        studyRoom();
    } else if (choice == 2) {
        printInColor("\nYou tried all doors but they all are locked\n");
    } else if (choice == 3) {
        printInColor("\nyou starved to death", "red");
    }
}

void studyRoom(std::string text) {
    StoryItem* studyroom = new StoryItem();

    if(text == "") {
        studyroom->preText = "\nWhen you enter the study you enconter the nostalgic smell of books.\n"
                             "You see many bookshelf all filled with books of many different genres\n";
    }else {
        studyroom->preText = text;
    }
                          
    studyroom->preTextColour = "magenta";

    studyroom->options = {
        "Check Left Bookshelf",
        "Check Middle Bookshelf",
        "Check Right Bookshelf",
        "Go Back to Ground Floor corridor",
    };

    int choice = studyroom->run();

    if(choice == 1) {
        // printInColor("\nYou see Lots of Books about Psychology\n");
        studyRoom("\nYou see Lots of Books about Psychology\n");
    }else if (choice == 2) {
        // printInColor("\nYou see Lots of Books about Detective/Thrillers\n");
        studyRoom("\nYou see Lots of Books about Detective/Thrillers\n");
    }else if (choice == 3) {
        // printInColor("\nYou see Lots of Books with mixed genre are placed in this shelf\n");
        studyRoom("\nYou see Lots of Books with mixed genre are placed in this shelf\n");
    }else if (choice == 4) {
        groundFloor();
    }
}