#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Abcd {
    int a;
    char b;
    bool c;
    float d = 1.2123;
};

union InC {
    int a;
    char c;
    bool d;
};

enum StatusCode {
    SUCCESS = 200,
    ERROR = 500,
};

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    // cout<< "Do something about it will you" << endl;
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of int: " << sizeof(long int) << " bytes" << endl;
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of char: " << sizeof(char) << " byte" << endl;
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes";
    cout << endl;
    cout << endl;

    // int var = 10;

    // int* ptr;
    // cout<< ptr << endl;

    // ptr = &var;

    // cout<< ptr << endl;
    // cout<< *ptr << endl;
    // cout << endl;

    // bool mainVar = true;
    // bool* pointer = &mainVar;

    // cout<< mainVar << endl;
    // cout<< pointer << endl;
    // cout<< *pointer << endl;

    // int num = 1209484;

    // int& ref = num;

    // cout << num << "-" << ref << " - ";
    // ref = 999999;
    // cout << ref << "-" << num;

   

    // Abcd obj;
    // obj.b = 'B';
    // obj.c = true;

    // cout << obj.a << endl;
    // cout << obj.b << endl;
    // cout << obj.c << endl;
    // cout << obj.d << endl;

    // InC ch;
    // ch.a =70;
    // ch.d = true;
    // cout << ch.a << endl;
    // cout << ch.c << endl;

    // enum StatusCode status;
    // status = ERROR;
    // cout << status << endl;

    //for js

    // using var = string;
    // var jsVariable = "this code can now work in js too";
    // cout << jsVariable << endl;



    cout << endl;
    cout << endl;
    
    return 0;
}
