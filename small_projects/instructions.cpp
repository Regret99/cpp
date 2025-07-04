#include <iostream>
#include <string>
#include <ctime>
#include <cstring> // For strlen()


using namespace std;

extern int globalExtVar; // getting from global.cpp

#define SQUARE(x) (x * x) // macro
#define LOG(msg) \
    { \
        time_t now = time(0); \
        char* dt = ctime(&now); \
        dt[strlen(dt) - 1] = '\0';  /* Remove newline character */ \
        std::cout << "[LOG - " << dt << "]: " << msg << std::endl; \
    }


#define CLERK 10
#define WORKER CLERK

int returnCount() {
  
    // Static variable
  static int count = 0;
  count++;
  return count;
}

class Mut {
    public: 
        int x;
        mutable int y;

        Mut(): x(4), y(10) {}
};

inline int square(int x) {
    return x * x;
}

class MemFunc {
    public:
    void memberName(string name);
};

void MemFunc::memberName(string name) {
    cout << "The name of this family member is " << name << endl;
}

class FriendOfFriend {
    private: 
        int length;
    public: 
        FriendOfFriend(int l) : length(l) {};
    
        friend void printLength(FriendOfFriend b);
};
void printLength(FriendOfFriend b) {
    cout << "Length of the Friend var: " << b.length << endl;
}

int main() 
{
    LOG("Application started");

    auto a = 3234;
    auto b = "this is a string";

    LOG("Result Computed: " << b);

    cout << a << endl;
    cout << b << endl;

    // cout<< globalExtVar << endl;

    // cout << returnCount() << endl;
    // cout << returnCount() << endl;
    // cout << returnCount() << endl;
    
    // const Mut obj;
    // obj.y = 200; //cuz it's mutable otherwise throw error
    // cout << obj.y << endl;

    // cout << "square of 73 - " << square(73) << endl; // replaces the function call overhead with function defination for faster exec

    // cout << "square of 73 using macro instead - " << SQUARE(73) << endl;

    // cout << WORKER;

    // MemFunc familyMember;
    // familyMember.memberName("PankaJ");

    // int abacas = nullptr;
    // FriendOfFriend fd(10);
    // printLength(fd);

    

    cout<<endl;
    return 0;
}