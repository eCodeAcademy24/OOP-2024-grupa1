#include <iostream>

using namespace std;

void func(int a = 1, int b = 2, int c = 3) {
    cout << a << " " << b << " " << c << endl;
}

int main() {
    //prv nachin
    func();

    //vtor nachin
    func(50);

    //tret nachin
    func(50, 25);

    //cetvrti nachin
    func(50, 25, 100);

    return 0;
}
