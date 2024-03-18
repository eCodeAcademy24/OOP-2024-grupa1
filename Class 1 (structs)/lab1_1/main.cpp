#include <iostream>
#include <cstring>
//
//Да се напише програма во која од стандарден влез се вчитува N (бројот на производи), а потоа се вчитуваат податоците за N производи (име, цена, количина).
// Програмата треба на стандарден излез да ја отпечати листата на купени производи и вкупната сума која треба да се плати во следниот облик (пример):
//
//1. Flips    10.00 x 3 = 30.00
//2. CocaCola 75.00 x 2 = 150.00
//3. ChokoBanana  5.00 x 10 = 50.00
//Total: 230.00

//Input
//3
//flips 10 3
//cocaCola 75 2
//chokoBanana 5 10
//Output
//1. Flips	10.00 x 3.0 = 30.00
//2. CocaCola	75.00 x 2.0 = 150.00
//3. ChokoBanana	5.00 x 10.0 = 50.00
//Total: 230.00
using namespace std;

struct Proizvod {
    char ime[100];
    double suma;
    int kolichina;
};

//typedef struct Proizvod {
//    char ime[100];
//    double suma;
//    int kolichina;
//} Proizvod;

void print(Proizvod proizvodi[], int n) {
    int vkupno = 0;
    int index = 1;
    for (int i = 0; i < n; i++) {
        proizvodi[i].ime[0] = toupper(proizvodi[i].ime[0]);
        int zaPlakjanje = proizvodi[i].suma * proizvodi[i].kolichina;
        //1. Flips	10.00 x 3.0 = 30.00
        cout << index++ << ". " << proizvodi[i].ime << " " << proizvodi[i].suma << " x " << proizvodi[i].kolichina
             << " = " << zaPlakjanje << endl;

        vkupno += zaPlakjanje;
    }
    //Total: 230.00
    cout << "Total: " << vkupno;
}

int main() {
    int n;
    cin >> n;

    Proizvod proizvodi[100];

    for (int i = 0; i < n; i++) {
        cin >> proizvodi[i].ime >> proizvodi[i].suma >> proizvodi[i].kolichina;
    }

    print(proizvodi, n);
    return 0;
}
