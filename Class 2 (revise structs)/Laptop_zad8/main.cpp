#include <iostream>
//Во програмскиот јазик C++ да се креира структура Laptop за опишување на спецификациите на даден преносен компјутер. Структурата треба да содржи: (5 поени)
//
//Фирма која го произведува ( низа од 100 знаци)
//Големина на монитор во инчи (реален број)
//Дали е со touch или не (булова променлива)
//Цена (цел број)
//Да се креира структура ITStore, што содржи: (5 поени)
//
//Име на продавницата (низа од 100 знаци)
//Локација (низа од 100 знаци)
//Низа од достапни лаптопи (низа од максимум 100 елементи од структурата Laptop)
//Број на елементи во низата (цел број)
//Да се креира функција print за печатење на информациите за сите лаптопи во една продавница во формат: (10 поени)
//
//[Ime na prodavnicata] [Lokacija]
//[Marka1] [dim_monitor1] [Cena1]
//[Marka2] [dim_monitor2] [Cena2]
//[Marka3] [dim_monitor3] [Cena3]
//...
//Да се креира функција najeftina_ponuda, што прима низа од променливи од типот ITStore и го печати името и локацијата на онаа продавница која нуди најевтин преносен компјутер
// и неговата цена. Најефтин преносен компјутер е оној што има најниска цена и плус опција за touch. Ако има повеќе такви продавници, се печати прво најдената.* (15 поени)*
//
//Да се дополни функцијата main (10 поени).
//
//Од тастатура се внесува бројот на продавници, па потоа за секоја продавница се внесуваат името и локацијата, а потоа бројот на компјутери,
// па за секој од компјутерите фирма која го произведува, големина на монитор, дали има touch и цена. Потоа се печатат сите внесени продавници и најевтината понуда.

//Input
//1
//AMC
//Skopje
//3
//hp
//13.3
//1
//42000
//asus
//15.0
//0
//20200
//dell
//13.3
//1
//32500
//Output
//AMC Skopje
//hp 13.3 42000
//asus 15 20200
//dell 13.3 32500
//Najeftina ponuda ima prodavnicata:
//AMC Skopje
//Najniska cena iznesuva: 32500

using namespace std;
struct Laptop {
    char manufacturer[100];
    double size;
    bool isTouch;
    int price;
};

struct ITStore {
    char name[100];
    char location[100];
    Laptop laptops[100];
    int numLaptops;
};

void print(ITStore *s, int n) {
    for (int i = 0; i < n; i++) {
        cout << s[i].name << " " << s[i].location << endl;

        for (int j = 0; j < s[i].numLaptops; j++) {
            cout << s[i].laptops[j].manufacturer << " " << s[i].laptops[j].size << " " << s[i].laptops[j].price << endl;
        }
    }
}

void najeftina_ponuda(ITStore *s, int n) {
    int minStorePrice = s[0].laptops[0].price;
    int indexI = 0;
    bool flag = true;
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < s[i].numLaptops; j++) {
            if (s[i].laptops[j].isTouch && flag) {
                minStorePrice = s[i].laptops[j].price;
                indexI = i;
                flag = false;
                continue;
            }

            if (s[i].laptops[j].isTouch && minStorePrice > s[i].laptops[j].price) {
                minStorePrice = s[i].laptops[j].price;
                indexI = i;
            }
        }
    }

    cout << "Najeftina ponuda ima prodavnicata:" << endl << s[indexI].name << " " << s[indexI].location << endl;
    cout << "Najniska cena iznesuva: " << minStorePrice;
}

int main() {
    //TODO: Inicijalizacija na niza od ITStore strukturi
    ITStore s[100];
    int n;
    cin >> n; //broj na IT prodavnici

    //TODO: vnesuvanje na prodavnicite edna po edna, zaedno so raspolozlivite laptopvi vo niv
    for (int i = 0; i < n; i++) {
        cin >> s[i].name >> s[i].location;
        cin >> s[i].numLaptops;

        for (int j = 0; j < s[i].numLaptops; j++) {
            cin >> s[i].laptops[j].manufacturer >> s[i].laptops[j].size >> s[i].laptops[j].isTouch
                >> s[i].laptops[j].price;
        }
    }

    //TODO: pecatenje na site prodavnici
    print(s, n);

    //TODO: povik na glavnata metoda
    najeftina_ponuda(s, n);
    return 0;
}
