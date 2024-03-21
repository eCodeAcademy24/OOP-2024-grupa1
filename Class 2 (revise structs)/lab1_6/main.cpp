#include <iostream>
#include <cstring>
//За програмски јазик да се употреби C++.
//
//Да се креира структура Employee во која се чуваат податоци за еден вработен. За вработениот се чуваат информации за името на вработениот (низа од карактери),
// матичен број (ЕМБГ) на вработениот(низа од карактери), име на одделот во кој што работи (низа од карактери), плата (цел број).
//
//Потоа, да се креира структура Company во која се чуваат податоци за името на компанијата (низа од карактери), низа од вработени во компанијата и број на вработени.
//
//Да се направи функција:
//
//void printEmployeesBelowAverageSalary(Company *comp, int numCompanies)
//
//која што за секоја компанија, ќе ги испечати сите вработени чија што плата е пониска од просекот на платите на сите вработени во таа компанија.
//
//Да се направи функција:
//
//void printHighestSalaryEmployee(Company *comp, int numCompanies, char *department)
//
//кoja што за секоја компанија ќе го испечати вработениот со највисока плата во дадениот оддел.
//
//Напомена: Прво од тастатура се чита бројот на компании, потоа компаниите (името и бројот на вработени), а потоа податоците за нивните вработени соодветно,
// a на крај се чита одделот кој што ќе биде искористен во printHighestSalaryEmployee функцијата.

//Input
//2
//Apple
//3
//Vlatko 111111 IT 150000
//Nikola 222222 IT 125000
//Marko 333333 Accounting 50000
//Google
//2
//Stefan 444444 IT 150000
//John 555555 HR 60000
//IT

//Output
//Employees with salaries below the average:
//Marko 333333 Accounting 50000
//John 555555 HR 60000
//Employees with highest salaries for given department:
//Vlatko 111111 IT 150000
//Stefan 444444 IT 150000
using namespace std;

//Да се креира структура Employee во која се чуваат податоци за еден вработен. За вработениот се чуваат информации за името на вработениот (низа од карактери),
// матичен број (ЕМБГ) на вработениот(низа од карактери), име на одделот во кој што работи (низа од карактери), плата (цел број).
struct Employee {
    char name[100];
    char embg[100];
    char department[100];
    int salary;
};

//Потоа, да се креира структура Company во која се чуваат податоци за името на компанијата (низа од карактери), низа од вработени во компанијата и број на вработени.
struct Company {
    char name[100];
    Employee employees[100];
    int numEmployees;
};

//која што за секоја компанија, ќе ги испечати сите вработени чија што плата е пониска од просекот на платите на сите вработени во таа компанија.
void printEmployeesBelowAverageSalary(Company *comp, int numCompanies) {
    //Employees with salaries below the average:
    //Marko 333333 Accounting 50000
    //John 555555 HR 60000

    cout << "Employees with salaries below the average:" << endl;
    for (int i = 0; i < numCompanies; i++) {
        int sumSalary = 0;
        for (int j = 0; j < comp[i].numEmployees; j++) {
            sumSalary += comp[i].employees[j].salary;
        }

        double average = (double) sumSalary / comp[i].numEmployees;

        for (int j = 0; j < comp[i].numEmployees; j++) {
            if (comp[i].employees[j].salary < average) {
                cout << comp[i].employees[j].name << " " << comp[i].employees[j].embg << " "
                     << comp[i].employees[j].department << " " << comp[i].employees[j].salary << endl;
            }
        }
    }
}

//кoja што за секоја компанија ќе го испечати вработениот со највисока плата во дадениот оддел.
void printHighestSalaryEmployee(Company *comp, int numCompanies, char department[]) {
    //Employees with highest salaries for given department:
    //Vlatko 111111 IT 150000
    //Stefan 444444 IT 150000
    cout << "Employees with highest salaries for given department:" << endl;

    for (int i = 0; i < numCompanies; i++) {
        bool flag = true;
        int maxSalary = 0;
        int indexJ = 0;

        for (int j = 0; j < comp[i].numEmployees; j++) {
            if (strcmp(comp[i].employees[j].department, department) == 0 && flag) {
                maxSalary = comp[i].employees[j].salary;
                indexJ = j;
                flag = false; // maxSalary e inicijalizirano
                continue;
            }

            if (strcmp(comp[i].employees[j].department, department) == 0
                /* && maxSalary < comp[i].employees[j].salary */) {
                if (maxSalary < comp[i].employees[j].salary) {
                    maxSalary = comp[i].employees[j].salary;
                    indexJ = j;
                }
            }
        }

        cout << comp[i].employees[indexJ].name << " " << comp[i].employees[indexJ].embg << " "
             << comp[i].employees[indexJ].department << " " << comp[i].employees[indexJ].salary << endl;
    }
}

//2
//Apple
//3
//Vlatko 111111 IT 150000
//Nikola 222222 IT 125000
//Marko 333333 Accounting 50000
//Google
//2
//Stefan 444444 IT 150000
//John 555555 HR 60000
//IT
int main() {

    int numCompanies;
    cin >> numCompanies;

    Company comp[numCompanies];

    for (int i = 0; i < numCompanies; i++) {
        cin >> comp[i].name;
//        int numEmployees;
//        cin >> numEmployees;
//        comp[i].numEmployees = numEmployees;
        cin >> comp[i].numEmployees;

        for (int j = 0; j < comp[i].numEmployees; j++) {
            cin >> comp[i].employees[j].name >> comp[i].employees[j].embg >> comp[i].employees[j].department
                >> comp[i].employees[j].salary;
        }
    }

    char department[100];
    cin >> department;

    printEmployeesBelowAverageSalary(comp, numCompanies);
    printHighestSalaryEmployee(comp, numCompanies, department);
    return 0;
}
