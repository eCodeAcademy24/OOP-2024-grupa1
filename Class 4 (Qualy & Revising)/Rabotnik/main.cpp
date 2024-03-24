#include <iostream>
#include <cstring>
//Креирајте класа Rabotnik која во себе содржи:
// ime (низа од максимум 30 знаци)
// prezime (низа од максимум 30 знаци)
// plata (целобројна вредност)

//За оваа класа да се креираат default конструктор и конструктор со аргументи. Да се имплементираат и следните методи:
// getPlata() која ја враќа платата на работникот
// pecati() која ги печати името, презимето и платата

//Креирајте класа Fabrika во која има:
// rabotnik[100] (низа од вработени)
// brojVraboteni (целобројна вредност)

//Во класата имплементирајте ги следните методи:
// pecatiVrednosti() ги печати сите вработени
// pecatiSoPlata(int plata) ги печати сите вработени со плата поголема или еднаква на дадената во аргумент int plata;

//Во главната функција се внесуваат податоци за n вработени. Притоа прво се внесува n, па податоците за сите n вработени.
// Во последниот ред се чита минималната плата. На излез да се прикажат прво сите вработени, а потоа само оние со поголема
// плата од минималната. Треба да се користат методите pecatiVrednosti i pecatiSoPlata.

//Input
//6
//Jovan Jovanoski 20000
//Zoran Ivanovski 50000
//Mia Sarkovska 66320
//Elena Zafirovska 10720
//Vesna Zlatevska 100000
//Viktor Zlatevski 12000
//23000
//Output
//Site vraboteni:
//Jovan Jovanoski 20000
//Zoran Ivanovski 50000
//Mia Sarkovska 66320
//Elena Zafirovska 10720
//Vesna Zlatevska 100000
//Viktor Zlatevski 12000
//Vraboteni so plata povisoka od 23000:
//Zoran Ivanovski 50000
//Mia Sarkovska 66320
//Vesna Zlatevska 100000

using namespace std;

class Rabotnik {
private:
    char ime[30];
    char prezime[30];
    int plata;

public:
    Rabotnik() {}

    Rabotnik(char *ime, char *prezime, int plata) {
        strcpy(this->ime, ime);
        strcpy(this->prezime, prezime);
        this->plata = plata;
    }

    ~Rabotnik() {}

    int getPlata() {
        return plata;
    }

    //Jovan Jovanoski 20000
    void pecati() {
        cout << ime << " " << prezime << " " << plata << endl;
    }
};


class Fabrika {
private:
    Rabotnik rabotnik[100];
    int brojVraboteni;
public:
    Fabrika() {}

    Fabrika(Rabotnik *rabotnik, int brojVraboteni) {
        this->brojVraboteni = brojVraboteni;

        for (int i = 0; i < brojVraboteni; i++) { // mozhe i so this->brojVraboteni
            this->rabotnik[i] = rabotnik[i];
        }
    }

    ~Fabrika() {}

    void pecatiVrednosti() {
        for (int i = 0; i < brojVraboteni; i++) {
            rabotnik[i].pecati();
        }
    }

    void pecatiSoPlata(int plata) {
        for (int i = 0; i < brojVraboteni; i++) {
            if (rabotnik[i].getPlata() >= plata) {
                rabotnik[i].pecati();
            }
        }
    }
};


//Input
//6
//Jovan Jovanoski 20000
//Zoran Ivanovski 50000
//Mia Sarkovska 66320
//Elena Zafirovska 10720
//Vesna Zlatevska 100000
//Viktor Zlatevski 12000
//23000
int main() {
    int n;
    cin >> n;

    Rabotnik r[100];

    for (int i = 0; i < n; i++) {
        char ime[30];
        char prezime[30];
        int plata;
        cin >> ime >> prezime >> plata;

        Rabotnik rabotnik(ime, prezime, plata);
        r[i] = rabotnik;
    }

    int salary;
    cin >> salary;


    Fabrika fabrika(r, n);


    //Site vraboteni:
    //Jovan Jovanoski 20000
    //Zoran Ivanovski 50000
    //Mia Sarkovska 66320
    //Elena Zafirovska 10720
    // Vesna Zlatevska 100000
    //Viktor Zlatevski 12000

    cout << "Site vraboteni:" << endl;
    fabrika.pecatiVrednosti();

    //Vraboteni so plata povisoka od 23000:
    //Zoran Ivanovski 50000
    //Mia Sarkovska 66320
    //Vesna Zlatevska 100000
    cout << "Vraboteni so plata povisoka od " << salary << ":" << endl;
    fabrika.pecatiSoPlata(salary);

    return 0;
}
