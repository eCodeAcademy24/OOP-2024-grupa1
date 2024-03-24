#include <iostream>
#include <cstring>

struct Employee {
    char name[100];
};

typedef struct Company {
    Employee emp[50];
} comp;

using namespace std;
//
//class Company {
//private:
//    Employee emp[50];
//    char name[50];
//public:
//    Company() {}
//
//    Employee *getEmployee() {
//        return emp;
//    }
//};

int main() {

    comp comp;
    comp.emp[0].name;
//    Company c;
//    c.getEmployee()[0].name;

    return 0;
}
