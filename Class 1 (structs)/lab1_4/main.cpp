#include <iostream>
//
//Да се напише програма во која од стандарден влез се внесува бројот N (бројот на трансакции), а потоа N трансакциски сметки и
// како резултат ги печати идентификацискиот број и вкупната сума (со провизија) на сите трансакции платени со кредитна картичка.
// Во случај да нема трансакција платена со кредитна картичка да се испечати "No credit card transaction".
//
//Во структурата Трансакција (Transaction) треба да се чуваат следните информации:
//- Идентификациски број (int)
//- Платена сума (int)
//- Провизија (int)
//- Дали е платено со дебитна или кредитна картичка (0 - дебитна, 1 - кредитна)
//
//Ограничување: 0 < N < 100
//
//Структура на влезните податоци:
//N
//id1 sum1 commission1 type1
//...
//idn sumn Commissionn typen

//Input
//3
//1 100 10 0
//2 202 20 1
//3 10 1 1
//Output
//2 222
//3 11

//Input
//
//5
//1 10 213 0
//2 20 123 0
//3 30 587 0
//4 40 342 0
//5 50 342 0
//Output
//No credit card transaction

using namespace std;

typedef struct Transakcija {
    int id;
    int suma;
    int provizija;
    bool tip;
} Transakcija;

void print(Transakcija transakcii[], int n) {
    bool flag = true; // nema nitu edna transakcija izvrshena so kreditna karticka
    for (int i = 0; i < n; i++) {
        if (transakcii[i].tip) {
            int vkupnaSuma = transakcii[i].suma + transakcii[i].provizija;
            //2 222
            cout << transakcii[i].id << " " << vkupnaSuma << endl;
            flag = false; // ima takva transakcija
        }
    }

    if (flag) {
        cout << "No credit card transaction";
    }
}

int main() {
    int n;
    cin >> n;

    Transakcija transakcii[100];

    for (int i = 0; i < n; i++) {
        //id1 sum1 commission1 type1
        cin >> transakcii[i].id >> transakcii[i].suma >> transakcii[i].provizija >> transakcii[i].tip;
    }

    print(transakcii, n);
    return 0;
}
