
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <map>
#include <termios.h>
#include <unistd.h>
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

int int_to_string(const std::string& string_in)
{
    try {
        return std::stoi(string_in);  // Converts string to int
    } catch (...) {
        return -1; // Return -1 if conversion fails
    }
}


int int_option(int max_digit)
{
    string prompt = "Enter a value between 1 and " + to_string(max_digit) + ": ";
    printInColor(prompt, "blue", false);

    if (cin.peek() == '\n')
        cin.ignore();

    bool valid_in = false;
    string stringIn = "-1";
    int answer;
    while (!valid_in) {
        getline(cin, stringIn);
        if (stringIn.length() == 1) {
            answer = int_to_string(stringIn);
        }
        if (answer > 0 & answer <= max_digit) {
            valid_in = true;
        } else {
            printInColor("Invalid option. Try again...", "red");
            printInColor(prompt, "blue", false);
        }
    }
    return answer;
}

void waitForKeyPress() {
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);           // save old settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);         // disable buffering and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);  // apply new settings

    getchar(); // wait for any key press

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // restore old settings
}