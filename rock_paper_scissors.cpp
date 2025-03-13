#include <iostream>
#include <string>
#include <algorithm>  // For transform
#include <cstdlib>    // For rand() and srand()
#include <ctime>      // For time()
#include <limits>     // For numeric_limits

#ifdef _WIN32
    #include <windows.h>  // For Sleep() in Windows
#else
    #include <unistd.h>   // For sleep() in Linux/Unix
#endif


using namespace std;

int rockPaperScissors(string userAnswer, string compAnswer) {
    
    if (userAnswer == "paper" && compAnswer == "stone") {
            return 1;
    }
    if (userAnswer == "stone" && compAnswer == "scissors") {
        return 1;
    }
    if (userAnswer == "scissors" && compAnswer == "paper") {
        return 1;
    }
    return 0;
}

void choseAgain(bool choice) {

}

int main() 
{   
    // Initialize random seed
    srand(time(0));

    string userInput,userAnswer,playAgain;
    string choices[] = {"rock","paper","scissors"};
    string computerChoice;
    int answer;
    bool throwOut = false;
    // string userAnswer;

    
    while(true) {
        
        system("clear");
        cout<< "Welcome to the Rock, Paper or Scissors Game. \n\n";

        if(throwOut) {
            cout << "Computer also chose the same \n\n";
            cout << "Choose Again :) \n\n";
        }

        userAnswer = "";
        playAgain = "yes";
        throwOut = false;


        cout << "Rock, Paper or Scissors. \n\n";
        cin >> userInput;
        cout << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n";
        userAnswer = userInput;
        
        transform(userAnswer.begin(), userAnswer.end(), userAnswer.begin(), ::tolower);
        
        if(userAnswer == "rock" || userAnswer == "scissors" || userAnswer == "paper") {
            
            cout<< "You Chose - " << userInput << "\n\n";

            // string computerChoice = choices[rand() % 3];
            string computerChoice = choices[1];
            
            if(userAnswer != computerChoice) {
                answer = rockPaperScissors(userAnswer,computerChoice);

                cout << "Computer Chose - " << computerChoice << "\n\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n";

                if(answer) {
                    cout << "!!!!! Congrats You Won !!!!! \n\n";
                }else {
                    cout << "!!!!! Computer won !!!!! - ";
                    cout << "Better Luck Next Time !!!! \n\n";
                }
                // break;
            }else {

                throwOut = true;
            }
        }else {
            cout<< "Please Select only one Rock, Paper or Scissors. \n\n";
            throwOut = true;
        }

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n";

        if(!throwOut) {
            cout << "Play Again? \n\n";
            cout << "Enter Yes/y or No/n \n";
            cin >> playAgain;
            cout<< endl;
        }

        transform(playAgain.begin(), playAgain.end(), playAgain.begin(), ::tolower);

        
        if(playAgain == "yes" || playAgain == "y") {
            continue;
        }else{
            break;
        }
        cin.clear();                // Clears the error flag on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discards the invalid input from the buffer
    }

    cout << "Thank you for playing!\n";
    sleep(3);
    exit(0);  // Exits the program
    // system(./myprogramm)

    return 0;
}