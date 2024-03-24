#include <iostream>
#include<cstring>

using namespace std;

int main() {
    struct book {
        int pages;
        char name[10];
    } a;

    a.pages = 10;
    strcpy(a.name, "OOP");
    cout << a.name << " " << a.pages;
    return 0;
}
