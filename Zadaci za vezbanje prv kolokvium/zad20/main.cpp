#include <iostream>

using namespace std;

//Во програмскиот јазик C++ да се креира структура Pacient и истата треба да содржи: (5 поени)
//
//Име и презиме на пациентот ( низа од макс. 100 знаци)
//Дали е здраствено осигуран (1-да, 0-не)
//Број на прегледи во текот на последниот месец (цел број)
//Да се креира структура MaticenDoktor, која во себе содржи: (5 поени)
//
//Име на докторот (низа од 100 знаци)
//Број на пациенти (цел број)
//Листа од пациенти (низа од максимум 200 елементи од структурата Pacient)
//Цена на преглед (децимален број)
//Да се креираат метода najuspesen_doktor, која прима низа од променливи од типот MaticenDoktor и нивниот број;
// и го печати името, заработената сума и бројот на прегледи на оној доктор кој
// заработил најголема сума од пациенти кои ги прегледувал приватно (не се здраствено осигурани) (10 поени).
// Доколку два или повеќе доктори имаат иста сума, тогаш се печати оној доктор кој
// има направено најголем број на прегледи вкупно во текот на последниот месец. (20 поени)
//
//Функционалност (5 поени)

struct Patient {
    char fullName[100];
    bool isInsured;
    int appointments;
};

struct Doctor {
    char name[100];
    int numPatients;
    Patient patients[200];
    int priceAppointment;
};

void najuspesen_doktor(Doctor *doctors, int numDoctors) {
    int maxSum = 0;
    int maxAppointments = 0;
    int indexI = 0;

    for (int i = 0; i < numDoctors; i++) {
        int sumFromAppointments = 0;
        int privateAppointments = 0;
        int allAppointments = 0;

        for (int j = 0; j < doctors[i].numPatients; j++) {
            if (doctors[i].patients[j].isInsured == 0) {
                sumFromAppointments += doctors[i].priceAppointment * doctors[i].patients[j].appointments;
                privateAppointments += doctors[i].patients[j].appointments;
            }

            allAppointments += doctors[i].patients[j].appointments;
        }

        if (i == 0) {
            maxSum = sumFromAppointments;
            maxAppointments = allAppointments;
            indexI = i;
            continue;
        }

        if (maxSum < sumFromAppointments) {
            maxSum = sumFromAppointments;
            maxAppointments = allAppointments;
            indexI = i;
        } else if (maxSum == sumFromAppointments) {
            if (maxAppointments < allAppointments) {
                maxSum = sumFromAppointments;
                maxAppointments = allAppointments;
                indexI = i;
            }
        }
    }

    cout << doctors[indexI].name << " " << maxSum << " " << maxAppointments << endl;
}

//Input
//3
//Д-р.Јованка_Јовановска
//3
//300.00
//Јованова_Ивана 1 2
//Боцевска_Ивана 0 3
//Илиевска_Ангела 1 0
//Д-р.Петко_Петковски
//1
//50.00
//Ивановска_Цветанка 0 18
//Д-р.Трајче_Трајчев
//3
//300.00
//Крстевски_Филип 1 0
//Цветановски_Иван 1 10
//Ивановска_Цветанка 0 3

//Output
//Д-р.Петко_Петковски 900 18
int main() {
    int n;
    cin >> n;

    Doctor doctors[n];

    for (int i = 0; i < n; i++) {
        cin >> doctors[i].name;
        cin >> doctors[i].numPatients;
        cin >> doctors[i].priceAppointment;

        for (int j = 0; j < doctors[i].numPatients; j++) {
            cin >> doctors[i].patients[j].fullName;
            cin >> doctors[i].patients[j].isInsured;
            cin >> doctors[i].patients[j].appointments;
        }
    }

    najuspesen_doktor(doctors, n);
    return 0;
}
