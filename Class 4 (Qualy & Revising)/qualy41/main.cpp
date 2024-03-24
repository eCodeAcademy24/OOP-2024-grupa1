#include <iostream>

using namespace std;

struct tree {
    int h;
};

int main() {
    struct tree tree1;

    tree1.h = 9;
    cout << "Visina=" << tree1.h;
    return 0;
}
