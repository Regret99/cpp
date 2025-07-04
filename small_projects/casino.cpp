#include <iostream>
#include <unordered_map>
#include <algorithm> // For transform()


using namespace std;

// function declarations start
void showDifficultyScreen();
// function declarations end
int getRandomNumber(int range = 100) {
    return (rand() % range) + 1;  // Generates a number between 1 and 100
}
int getRandomNumberInRange(int min, int max) {
    return (rand() % (max - min + 1)) + min;  // Generates a number between min and max (inclusive)
}

std::unordered_map<int, std::string> difficulty = {
    {1, "Easy"},
    {2, "Normal"},
    {3, "Hard"}
};
std::unordered_map<int, int> difficultyModifier = {
    {1, 5},
    {2, 10},
    {3, 25}
};


inline void linebreak(int numLines = 1) {

  for (int i = 0; i < numLines; ++i) {
    cout << '\n';
  }
}

class PlayerInfo {
    public: 
        static int playerBalance;
        static int betAmount;
        static bool moneyDeposited;
        
    int setPlayerBalance() {
        cout << "Deposit money to play - ";
        cin >> playerBalance;
        moneyDeposited = true;
        linebreak();
        return playerBalance;
    }

    int getPlayerBalance() {
        return playerBalance;
    }

    int deductBalance() {
        int toDeduct;
        cin >> toDeduct;
        linebreak();
        playerBalance = playerBalance - toDeduct;
        // cout << "Balance now - " << playerBalance;
        return playerBalance;

    }

    int addBalance() {
        int toAdd;
        cin >> toAdd;
        linebreak();
        playerBalance = playerBalance + toAdd;
        return playerBalance;
    }
    
    int setBet() {
        int bet = 0;
        cout << "Enter the Amount you want to Bet - ";
        cin >> bet;
        if(bet > 0 && bet <= playerBalance) {
            betAmount = bet;
        } else {
            return 0;
        }
        linebreak();
        return betAmount;
    }
    int recursiveSetBet() {
        int bet = setBet();
        if (bet <= 0 || bet > playerBalance) {
            cout << "Bet must be greater than 0 and less than or equal to your current Balance" << endl;
            cout << "Your Current Balance is " << getPlayerBalance() << endl;
            recursiveSetBet();
        } else {
            cout << "You Bet For - " << bet << endl;
        }
        return bet;
    }

};
int PlayerInfo::playerBalance = 0;
int PlayerInfo::betAmount = 0;
bool PlayerInfo::moneyDeposited = false;

class GameSettings {
  public: 
    static int gameDifficulty;
    static bool difficultyChanged;
    static int startRange;
    int endRange;
    int setDifficulty() {
        cin >> gameDifficulty;
        difficultyChanged = true;
        linebreak();
        return gameDifficulty;
    }
    int getDifficulty() {
        return gameDifficulty;
    }
    bool getDifficultyChange() {
        return difficultyChanged;
    }
    void setRanges(int num) {
        startRange = num;
        int difference =  difficultyModifier[gameDifficulty];
        endRange = startRange + difference;
    }
    int getStartRange() {
        return startRange;
    }
    int getEndRange() {
        return endRange;
    }
};
int GameSettings::gameDifficulty = 1;
int GameSettings::startRange = getRandomNumber(50);
bool GameSettings::difficultyChanged = false;

class GameResult {
    public:

    void doTranscation(int answer, int correctAnswer) {
        
    }
    void showResult(int answer, int correctAnswer) {
        if(answer == correctAnswer) {
            cout << "Correct Choice You Won The Bet !!" << endl;
        }else {
            cout << "Too Bad Wrong Choice :/" <<endl;
        }
    }
};

void showWelcomeScreen() {
  cout << "Welcome to the Casino Game !!!";
  linebreak(2);
}

void showDifficultyScreen() {

  cout << "Select a Difficulty. \n";

  cout << "- Easy => 1";
  linebreak();
  cout << "- Normal => 2";
  linebreak();
  cout << "- Hard => 3";
  linebreak(2);

  GameSettings setting;
  setting.setDifficulty();
//   cout << setting.getDifficulty();
}

bool continueGame(string input) {

    // Convert input to lowercase
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    // Check if input is "yes" or "y"
    return (input == "yes" || input == "y");
}


int main() {
    srand(time(0));

    // showWelcomeScreen();
    GameSettings setting;
    PlayerInfo info;
    GameResult calculate;
    int level = 0;
    int bet = 0;
    string playAgain = "Yes";
    int playerBalance = 0;


    while (true) {
        int startRange = 0;
        int endRange = 1;
        int correctNumber = 0;
        int playerChoice = 1;
        showWelcomeScreen();
        if(level == 0){
            showDifficultyScreen();
            level = setting.getDifficulty();
        }
    
        // system("clear");
        linebreak();
        cout << "Chosen Difficulty is "<< difficulty[setting.getDifficulty()] << endl;
        linebreak();
        playerBalance = info.getPlayerBalance();
        if(playerBalance <= 0) {
            info.setPlayerBalance();
        }

        cout << "Your Current Balance is " << info.getPlayerBalance() << endl;

        bet = info.recursiveSetBet();
        
        cout << "Starting the game round" << endl;

        setting.setRanges(getRandomNumber(50));
        startRange = setting.getStartRange();
        endRange = setting.getEndRange();
        correctNumber = getRandomNumberInRange(startRange,endRange);
        cout << "guess the number between "<< startRange << " and " << endRange << endl;
        linebreak();
        cout<< "Your Choice - ";
        cin >> playerChoice;
        linebreak();

        cout << "Correct Answer - " << correctNumber << endl;
        calculate.doTranscation(playerChoice,correctNumber);
        calculate.showResult(playerChoice,correctNumber);

        linebreak();

        cout << "Play Again? Y/N" <<endl;
        linebreak();
        cin >> playAgain;
        if(!continueGame(playAgain)){
            break;
        };
        linebreak(2);
    }

  linebreak(2);
  return 0;
}