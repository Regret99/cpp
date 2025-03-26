#ifndef HANGMAN_DEC_H
#define HANGMAN_DEC_H

#include <string>
#include <vector>

void greet(std::string name);
void welcome();
void drawHangman(int miss);
void drawLetters(const std::vector<char>& guessedWord);

#endif