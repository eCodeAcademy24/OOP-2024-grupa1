#include <iostream>

using namespace std;
struct st {
    int x;
    struct st *next;
};

int main() {
    struct st temp;
    int z = 15;
    temp.x = z;
    temp.next = &temp;
    temp.x = 10;
    cout << temp.next->x;
    return 0;
}