#include <iostream>
#include <memory> 


using namespace std;

class Engine {
    private: 

        int horsepower;

    public:
        Engine(int hp) : horsepower(hp) {}

        friend class Car;

};

class Car {
    public: 
        void showEngine(Engine e) {
            cout << "Engine HorsePower is " <<  e.horsepower << endl;
        }
};

class A {
    public:
        void display() {
            cout << "Unique pointer is shown?" << endl;
        }
};

class B {
    public:
        void display() {
            cout << "Shared pointer in all its glory?" << endl;
        }
};

int main() 
{

    Engine e1(200);
    Car c1;
    c1.showEngine(e1);
    cout << "\n\n";

    // unique_ptr<A> ptr1 (new A);
    // ptr1->display();

    // cout << ptr1.get() << endl;

    // unique_ptr<A> ptr2 =  move(ptr1);
    // ptr2->display();

    // cout << ptr1.get() << endl;
    // cout << ptr2.get() << endl;

    // unique_ptr<A> ptr3 = move(ptr2);
    // ptr3->display();

    // cout << ptr1.get() << endl;
    // cout << ptr2.get() << endl;
    // cout << ptr3.get() << endl;

    shared_ptr<B> sptr1 (new B);
    cout << sptr1.get() << endl;
    sptr1->display();

    shared_ptr<B> sptr2(sptr1);
    sptr2->display();
    cout << sptr2.get() << endl;

    shared_ptr<B> sptr3(sptr1);
    sptr3->display();
    cout << sptr3.get() << endl;
    
    cout<< endl << "ok" << endl;
    cout << sptr1.use_count() << endl;
    cout << sptr2.use_count() << endl;

    cout << endl << "nice?" << endl;

    sptr1.reset();

    cout << sptr1.get() << endl; 
    cout << sptr1.use_count() << endl; 
    // sptr2.reset();
    cout << sptr2.get() << endl; 
    cout << sptr2.use_count() << endl; 

    cout << "\n\n";
    return 0;
}