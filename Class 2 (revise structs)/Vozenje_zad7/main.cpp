#include <iostream>

//Во програмскиот јазик C да се креира структура Vozenje за опишување на адреналински возења во забавен парк. Структурата треба да содржи: (5 поени)
//
//Име на возењето ( низа од 100 знаци)
//Времетраење во минути (цел број)
//Цена (децимален број)
//Дали има студентски попуст (1-да, 0-не)
//Да се креира структура ZabavenPark, што содржи: (10 поени)
//
//Име на забавниот парк (низа од 100 знаци)
//Локација (низа од 100 знаци)
//Низа од адреналински возења во паркот (низа од максимум 100 елементи од структурата Vozenje)
//Број на елементи во низата (цел број)
//Да се креира функција print за печатење на информациите за сите возења во забавниот парк во формат: (10 поени)
//
//[Ime na parkot] [Lokacija]
//[Ime1] [Vremetraenje1] [Cena1]
//[Ime2] [Vremetraenje2] [Cena2]
//[Ime3] [Vremetraenje3] [Cena3]
//...
//Да се креира функција najdobar_park, што прима низа од променливи од типот ZabavenPark и го печати името и локацијата
// на паркот кој е најефтин за посета од страна на студенти. Најефтин парк е оној што содржи најголем број возења со студентски попуст.
// Ако повеќе паркови ги делат овие карактеристики, да се испечати паркот со најголемото времетраење од сите возења.* (20 поени)*
//
//Да се дополни функцијата main (5 поени).

//Input
//2
//Disneyland
//Paris
//2
//BigThunderMountain
//15
//10
//1
//Shark
//22
//13
//0
//TivoliGardens
//Copenhagen
//3
//Devil
//16
//11
//1
//FlyMountain
//35
//19
//1
//Nemo
//8
//7
//0
//Output
//Disneyland Paris
//BigThunderMountain 15 10.00
//Shark 22 13.00
//TivoliGardens Copenhagen
//Devil 16 11.00
//FlyMountain 35 19.00
//Nemo 8 7.00
//Najdobar park: TivoliGardens Copenhagen

using namespace std;

struct Vozenje {
    char ime[100];
    int vremetraenje;
    double cena;
    bool popust;
};

struct ZabavenPark {
    char ime[100];
    char lokacija[100];
    Vozenje v[100];
    int brV;
};

void pecati(ZabavenPark *zp, int n) {
    for (int i = 0; i < n; i++) {
        cout << zp[i].ime << " " << zp[i].lokacija << endl;

        for (int j = 0; j < zp[i].brV; j++) {
            cout << zp[i].v[j].ime << " " << zp[i].v[j].vremetraenje << " " <<
                 zp[i].v[j].cena << endl;
        }
    }
}

void najdobar_park(ZabavenPark *zp, int n) {
    int maxVremetraenje = 0;
    int indexI = 0;
    int maxVozenja = 0;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        int counter = 0;
        int vreme = 0;
        for (int j = 0; j < zp[i].brV; j++) {
            if (zp[i].v[j].popust) {
                ++counter;
            }

            vreme += zp[i].v[j].vremetraenje;
        }

        if (flag) {
            maxVozenja = counter;
            maxVremetraenje = vreme;
            indexI = i;
            flag = false;
            continue;
        }

        if (maxVozenja < counter) {
            maxVozenja = counter;
            indexI = i;
            maxVremetraenje = vreme;
        } else if (counter == maxVozenja && vreme > maxVremetraenje) {
            indexI = i;
            maxVremetraenje = vreme;
//            maxVozenja = counter; mozhe ama i ne mora
        }

    }

    cout << "Najdobar park: " << zp[indexI].ime << " " << zp[indexI].lokacija;
}

int main() {
    int i, j, n;
    cin >> n;
    //kreiraj niza od maksimum 100 zabavni parkovi
    ZabavenPark zp[100];
    //citanje na podatocite
    for (i = 0; i < n; i++) {
        //ime na festivalot
        cin >> zp[i].ime;
        //mesto
        cin >> zp[i].lokacija;
        //broj na filmovi
        cin >> zp[i].brV;

        for (j = 0; j < zp[i].brV; j++) {
            /* Ime na filmot */
            cin >> zp[i].v[j].ime;
            /* Vremetraenje   */
            cin >> zp[i].v[j].vremetraenje;
            /* Cena */
            cin >> zp[i].v[j].cena;
            /* Popust */
            cin >> zp[i].v[j].popust;

        }
    }
    pecati(zp, n);
    najdobar_park(zp, n);
    return 0;
}
