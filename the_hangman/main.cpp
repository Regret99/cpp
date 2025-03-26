#include <iostream>
#include <vector>
#include <string>
#include "hangman_dec.h"
#include <algorithm>

using namespace std;

class Word {
    public: 
        string secretWord = "secret";
        vector<char> guessedWord;
        int totalCorrect = 0;

        // Constructor to initialize guessedWord with '_'
        Word() : guessedWord(secretWord.length(), '_') {}
    
    string getSecretWord() {
        return secretWord;
    }

    void addGuessedWord(char guess) {
        for( size_t i = 0; i < secretWord.length(); ++i ) {
            if(secretWord[i] == guess) {
                guessedWord[i] = guess;
            }
            // if(secretWord[i] != '_') {

            // }
        }
    }
    void printWord() {
        drawLetters(guessedWord);
    }
    bool checkWord(char guess) {
        if (find(secretWord.begin(), secretWord.end(), guess) != secretWord.end()) {
            cout << endl;
            totalCorrect++;
            cout << guess << " Correct!!!\n";
            return true;
        } else {
            cout << endl;
            cout << guess << "Wrong too Bad .\n";
            return false;
        }
    }
    int getTotal() {
        return totalCorrect;
    }

};

int main () {

    welcome();

    Word word;
    int mistakes = 0;
    
    drawHangman(mistakes);
    
    vector<char> guessedWord(word.getSecretWord().length(), '_');
    // drawLetters(guessedWord);

    char guess;
    while(true) {
        word.printWord();

        cout << "Enter a Letter" << endl;
        cin >> guess;
        system("clear");
        cout << endl;
        word.addGuessedWord(guess);
        if(!word.checkWord(guess)){
            mistakes++;
        };
        drawHangman(mistakes);
        if(mistakes >=6) {
            cout << endl;
            cout << "The man Died :(" << endl;
            break;
        }
        if(word.getTotal() >= 6) {
            cout << endl;
            cout << "You Saved the Man Congratulations" << endl;
            break;
        }
    }

    cout << endl;
    return 0;
}