#include <iostream>

using namespace std;

class A {
public:
    A() {
        cout << "a";
    }

    ~A() {
        cout << "A";
    }
};

class B {
public:
    B() {
        cout << "b";
    }

    ~B() {
        cout << "B";
    }

    A a;
};


//Понудени одговори:
//baBA
//abAB
//abBA
//baBA
int main() {
    B b;
    return 0;
}
