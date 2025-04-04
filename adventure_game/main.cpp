#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <map>

using namespace std;

void typeText(const string& text, int delayMs = 50) {
    for (char c : text) {
        cout << c << std::flush;  // Print character and flush to display immediately
        this_thread::sleep_for(chrono::milliseconds(delayMs)); // Delay
    }
    cout << endl;  // Move to next line
}

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
            typeText("Welcome to The Bones Manor!!!!");
            typeText("This is the World of Bones Manor");
            typeText("Many exciting encouters Await!!");
            typeText("There are many rooms and lore there for you to Explore!!!");
            cout << endl;
            typeText("You arrive at the manor in the morning");
            typeText("since you have summer vacation going on you are going to be spending that time here in the Bones Manor");
            typeText("You ring the door bell after waiting a while you here a 'come in' and you enter the manor");
            typeText("You enter and see a big hallway, where you find your aunt");
            typeText("After exchanging greerting she leads to the room on second floor where you'll be staying the coming month");
            cout << endl;
        }
};
void start() {
    cout << endl;
    typeText("You decide to explore the manor before dinner");
}
int main () {

    World x;
    x.showIntro();

    Room* foyer = x.createRoom("Foyer", "A small, cozy foyer.");
    Room* hall = x.createRoom("Hall", "A long, dimly lit hallway.");

    cout << endl;
    return 0;
}