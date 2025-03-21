#include <iostream>
#include <string>
#include <cstdlib> // for exit function
#include <fstream>  // For file handling
#include <map>


#ifdef _WIN32
    #include <conio.h>  // Windows: use _getch()
    #define KEY_ENTER '\r'
#else
    #include <termios.h>
    #include <unistd.h>

    // Linux: Custom _getch() implementation
    char getch() {  
        struct termios oldt, newt;
        char ch;
        
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        
        ch = getchar();
        
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }

    #define KEY_ENTER 10
#endif


#define KEY_UP 65
#define KEY_DOWN 66
// #define KEY_ENTER '\r'

using namespace std;

int getCharCode() {
    char ch = getch();

    if (ch == 27) { // Escape sequence start (Arrow keys or ESC key)
        ch = getch();
        if (ch == 91) { // Arrow key sequence
            ch = getch(); // Get final keycode

            // switch (ch) {
            //     case 65: cout << "You pressed: UP Arrow Key\n"; break;
            //     case 66: cout << "You pressed: DOWN Arrow Key\n"; break;
            //     case 67: cout << "You pressed: RIGHT Arrow Key\n"; break;
            //     case 68: cout << "You pressed: LEFT Arrow Key\n"; break;
            //     default: cout << "Unknown key sequence\n"; break;
            // }
        } else {
            cout << "You pressed ESC (Exiting...)\n";
            return 0;
        }
    } else {
        // cout << "You pressed: " << ch << " (ASCII: " << int(ch) << ")\n";
    }
    return int(ch);
    
}
void saveInfo(string username, string password) {
    string filename = "data.txt";
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    if(file.is_open()){
        file << username << ":" << password << endl;
        file.close();
    }
}
// get user pass via username
string readInfo(string userName) {
    ifstream infile("data.txt");
    string line;

    if (!infile) {
        cerr << "Error opening file!" << endl;
        exit(1);
    }
    while(getline(infile, line)) {
        size_t pos = line.find(":"); // Find position of ':'
        if (pos != string::npos) {
            string username = line.substr(0, pos);   // Extract username
            string password = line.substr(pos + 1); // Extract password

            if (username == userName) {  // Check if it matches
                infile.close();
                return password;  // Return password
            }
        }
    }
    return "";
}

static int menuSelected = 0;
void selectionMenu() {
    int selected = 0;    //Keeps track of which option is selected.
    int numChoices = 2; //The number of choices we have.
    bool selecting = true;//True if we are still waiting for the user to press enter.
    bool updated = false;//True if the selected value has just been updated.
    
    std::cout << "1. Login <-\n";
    std::cout << "2. Registration \n";

    char c; //Store c outside of loop for efficiency.
    while (selecting) {
        c = char(getCharCode());
        // cout << getCharCode() <<endl;
        switch(c) {
            case KEY_UP:
                if(selected>0) { //Dont decrement if we are at the first option.
                    --selected;
                    updated = true;
                }
                break;
            case KEY_DOWN:
                if (selected < numChoices - 1) { //Dont increment if we are at the last option.
                    ++selected;
                    updated = true;
                }
                break;
            case KEY_ENTER:
                //We are done selecting the option.
                selecting = false;
                menuSelected = selected;
                break;
            default: break;
        }
        if (updated) { //Lets us know what the currently selected value is.
            system("clear");
            cout<<endl;
            cout << "Welcome to Arroganz Pvt.Ltd" << endl;
            cout << "Register or Login"<<endl;
            cout << "1. Login" << (selected == 0 ? " <-" : "") << "\n";
            cout << "2. Registration" << (selected == 1 ? " <-" : "") << "\n";
            updated = false;
        }
    }
}


void registeration() {
    system("clear");
    string userName;
    string password;

    cout<<endl;
    cout << "Register to Arroganz Pvt.Ltd" << endl;
    cout << "Register"<<endl;
    
    cout << "Enter Username - ";
    // cout << endl;
    cin >> userName;
    cout << endl;
    cout << "Enter Password - ";
    cin >> password;
    
    cout << "Username -" << userName;
    cout << endl;
    cout << "Pass - " << password;
    cout << endl;
    
    system("clear");
    cout<<endl;
    cout << "Register to Arroganz Pvt.Ltd" << endl;
    cout << endl;
    cout << userName << " You are Registered Successfully!!" << endl;
    cout << endl;

    map<string, string> users;
    users[userName] = password;
    // saveFile(users);
    saveInfo(userName,password);
}

void login() {
    system("clear");
    string userName;
    string password;

    cout<<endl;
    cout << "Login to Arroganz Pvt.Ltd" << endl;
    cout << "Login"<<endl;
    
    cout << "Enter Username - ";
    // cout << endl;
    cin >> userName;
    cout << endl;
    cout << "Enter Password - ";
    cin >> password;

    readInfo(userName);
    if(password == readInfo(userName)) {
        cout << "Logged In Successfully" << endl; 
        cout << "Welcome!!!" << endl;
        cout << endl;
    }else {
        cout << "Wrong user name or password" <<endl;
    }
}

void registerationMenu() {
    registeration();
}

void loginMenu() {
    login();
}

int main() {

    cout << "Welcome to Arroganz Pvt.Ltd" << endl;
    cout << "Register or Login"<<endl;

    selectionMenu();
    cout << endl;

    if(menuSelected == 1) {
        registerationMenu();
    }else {
        loginMenu();
    }


    cout << endl;
    cout << endl;
    return 0;
}