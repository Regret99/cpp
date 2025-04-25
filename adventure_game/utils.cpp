
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <map>
#include "utils.h"

using namespace std;

void typeText1(const string& text, int delayMs = 50) {
    for (char c : text) {
        cout << c << std::flush;  // Print character and flush to display immediately
        this_thread::sleep_for(chrono::milliseconds(delayMs)); // Delay
    }
    cout << endl;  // Move to next line
}

void typeText(const string& text) {
    cout<< text;
    cout << endl;
}

void printInColor(string text, string textColor, bool newLine) {
    string code = "\033[0m";
    if(textColor == "red") {
        code = "\033[1;31m";
    }else if(textColor == "black") {
        code = "\033[1;30m";
    }else if(textColor == "green") {
        code = "\033[1;32m";
    }else if(textColor == "yellow") {
        code = "\033[1;33m";
    }else if(textColor == "blue") {
        code = "\033[1;34m";
    }else if(textColor == "magenta") {
        code = "\033[1;35m";
    }else if(textColor == "cyan") {
        code = "\033[1;36m";
    }else if(textColor == "white") {
        code = "\033[1;37m";
    }

    if(newLine) {
        text += "\n";
    }

    cout << code + text + "\033[0m"; // reset

}