#include <iostream>

using namespace std;

class A {
public:
    A() {
        cout << "Constructor called";
    }

    ~A() {
        cout << "Destructor called";
    }
};

int main() {
    A obj1;
    int x = 1;
    if(x) {
        A obj2;
    }
    return 0;
}
