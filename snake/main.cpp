#include <iostream>
#include "utils.h"

using namespace std;

void drawBox() {
    constexpr int BorderHeight = 20;
    constexpr int BorderWidth = 70;
    int x = 0, y = 0;
    x = BorderHeight / 2;
    y = BorderWidth /2;
    cout << x << " " << y << endl;
    for (int i = 0; i < BorderHeight; i++) {
        for (int j = 0; j < BorderWidth; j++) {
            if (i==0 || i==BorderHeight - 1 || j == 0) {
                cout<< "*";
            }else if (i == x && j == y) {
                cout << "@"; // Center
            }else {
                cout<< " ";
            }
        }
        cout<<"*";
        cout << endl;
    }
}

int main() {

    printMessage();
    const char *msg = "oooooooooo@";
    cout<<msg<<endl;

    printInColor("Press Any Key to continue","white",true);
    cout << endl;
    waitForKeyPress();

    // drawBox();
    waitForUserInput();

    int count = 0;
    // while(true) {
    //
    //     if(count > 50){
    //         break;
    //     }else {
    //         // cout << "\033[2J\033[1;1H"; // Clears screen and moves cursor to top-left
    //         system("clear");
    //     }
    //     drawBox();
    //     waitForUserInput():
    //     count++;
    // }

    return 0;
}