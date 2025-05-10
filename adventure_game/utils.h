// utils.h
#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;

void typeText(const string& text);
void printInColor(string text="", string textColor="", bool newLine=true);
int int_to_string(const std::string& string_in);
int int_option(int max_digit);

#endif