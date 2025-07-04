#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // Required for std::setprecision


using namespace std;

class BankAccount {
    //Data memeber
    string accountHolderName;
    int accountNumber;
    double balance;

    public: 
        BankAccount() : accountHolderName("John Doe"), accountNumber(20001), balance(5000.00) {}

        void deposit(double amount) {
            balance = balance + amount;
            cout << fixed << setprecision(2);  // Ensure fixed notation and two decimal places
            cout << "Depositing $" << amount << "...\n";
            cout << "New Balance: $" << balance << endl;
            cout << endl;
        }
        void withdraw(double amount) {
            balance = balance - amount;
            cout << fixed << setprecision(2);
            cout << "Withdrawing $" << amount << "...\n";
            cout << "New Balance: $" << balance << endl;
            cout << endl;
        }
        void display() {
            cout << fixed << setprecision(2);
            cout << "Account Details: \n\n";
            cout << "Account Holder: " << accountHolderName << endl;
            cout << "Account Number: "<< accountNumber << endl;
            cout << "Balance: " << balance << endl;
            cout << endl;
            
        }
};

int main()
{

    cout << "Welcome to **** Bank \n\n";
    cout << "Account Created Successfully! \n\n";

    BankAccount one;
    BankAccount two;
    
    one.display();
    one.deposit(2183.01);
    one.withdraw(2000);

    one.display();

    cout << "\n\n";

    two.display();
    one.deposit(99999999);
    one.withdraw(2000);

    cout << "\n\n";
}