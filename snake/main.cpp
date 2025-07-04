#include <iostream>

using namespace std;

int main() {

    const char *msg = "oooooooooo@";
    cout<<msg<<endl;
    int count = 0;
    while(true) {
        cout<<" ";
        if(count > 50){
            break;
        }
        count++;
    }



    return 0;
}