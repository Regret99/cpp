//
// Created by rajat on 4/7/25.
//
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <string>
#include "utils.h"

void printMessage() {
    std::cout << "Hello from utils!" << std::endl;
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

void waitForKeyPress() {
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);           // save old settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);         // disable buffering and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);  // apply new settings

    getchar(); // wait for any key press

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // restore old settings
}

void set_terminal_echo(bool enable) {
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty); // Get current terminal attributes

    if (enable) {
        tty.c_lflag |= ECHO; // Enable echo
    } else {
        tty.c_lflag &= ~ECHO; // Disable echo
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &tty); // Apply new attributes immediately
}

void waitForUserInput() {
    std::string password;

    std::cout << "Enter password: ";
    std::flush(std::cout); // Ensure prompt is displayed before disabling echo

    set_terminal_echo(false); // Disable echo for password input

    std::getline(std::cin, password); // Read the password

    set_terminal_echo(true); // Re-enable echo

    std::cout << "\nPassword entered: " << password << std::endl;
}
