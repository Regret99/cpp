#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <map>
#include "utils.h"
#include "room_dec.h"
#include "story_item.h"


using namespace std;


class Room {
    public: 
        string name;
        string description;
        map<string, Room*> exits;

        Room(string n, string d) : name(n), description(d){}

        void addExit(const string& direction, Room* neighbor) {
            exits[direction] = neighbor;
        }
};

class World {
    public:

        vector<Room*> rooms;

        ~World() {
            for( Room* room : rooms) {
                delete room;
            }
        }

        Room* createRoom(const string& name, const string& desc){
            Room* room = new Room(name, desc);
            rooms.push_back(room);
            return room;
        };


        void showIntro() {
            cout << endl;
            printInColor("Welcome to The Bones Manor!!!!","cyan");
            printInColor("This is the World of Bones Manor","cyan");
            printInColor("Many exciting encouters Await!!","cyan");
            printInColor("There are many rooms and lore there for you to Explore!!!","cyan");
            cout << endl;
            string preText= "You arrive at the manor in the morning.\n"
                            "since you have summer vacation going on you are going to be spending that time here in the Bones Manor.\n"
                            "You ring the door bell after waiting a while you here a 'come in' and you enter the manor,\n"
                            "You enter and see a big hallway, where you find your aunt.\n"
                            "After exchanging greetings she leads to the room on second floor where you'll be staying the coming month.\n";
            printInColor(preText,"magenta");
        }
        void showRoomCount() {
            size_t count = rooms.size();
            cout << "Room Count is - " ;
            cout << count<<endl;
            cout<<rooms[1];

        }
};
void start() {
    cout << endl;
    typeText("You decide to explore the manor before dinner");
    typeText("You leave your room and enter the foyer");
}
int main () {

    bool quit = false;
    string charPos = "Foyer";
    World gameWorld;
    gameWorld.showIntro();
    int action = 0;

    Room* foyer = gameWorld.createRoom("Foyer", "A small, cozy foyer.");
    Room* hall = gameWorld.createRoom("Hall", "A long, dimly lit hallway.");
    // gameWorld.showRoomCount();

    // printInColor("Hello there","red",true);
    // printInColor("Hello there","black",true);
    // printInColor("Hello there","green",true);
    // printInColor("Hello there","yellow",true);
    // printInColor("Hello there","blue",true);
    // printInColor("Hello there","magenta",true);
    // printInColor("Hello there","cyan",true);
    // printInColor("Hello there","white",true);
    // printInColor("Hello there","",true);

    while(true) {

        printInColor("You are in the - ","blue",false);
        printInColor(charPos,"green");
        printInColor("Choose a action","blue");
        cout << "1. Look Around" << endl;
        cin >> action;
        foyerChoice();




    }


    cout << endl;
    return 0;
}