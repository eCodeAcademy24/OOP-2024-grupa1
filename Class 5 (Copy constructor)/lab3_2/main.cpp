#include <iostream>
#include <cstring>

using namespace std;

//Да се дефинира класа Potpisuvac во која се чуваат информации за:
//
//име (низа од максимум 20 знаци)
//презиме (низа од максимум 20 знаци)
//ЕМБГ (низа од максимум 14 знаци)
//За класата да се дефинира copy конструктор, default конструктор и конструктор со аргументи.
//
//Да се дефинира класа Dogovor, во која се чуваат информации за:
//
//број на договор (int),
//категорија на договор (низа од 50 знаци),
//поле од 3 потпишувачи на договорот (објекти од класата Potpisuvac)
//Во класата да се додаде метод кој ќе проверува дали постојат два исти потпишувачи (имаат ист ЕМБГ).

//Input
//2
//0101988450001 Alek Aleksov
//0101988450001 Alek Aleksov
//0202987440022 Marko Markov
//1 Osiguruvanje
//0101988450001 Alek Aleksov
//0101988450011 Tome Tomov
//0202987440022 Marko Markov
//2 Kreditiranje
//Output
//Dogovor 1:
//Postojat potpishuvaci so ist EMBG
//Dogovor 2:
//Ne postojat potpishuvaci so ist EMBG


class Potpisuvac {
    //vasiot kod tuka
private:
    char ime[20];
    char prezime[20];
    char EMBG[14];
public:
    Potpisuvac() {}

    Potpisuvac(char *name, char *lastName, char *EMBG) {
        strcpy(ime, name);
        strcpy(prezime, lastName);
        strcpy(this->EMBG, EMBG);
    }

    Potpisuvac(const Potpisuvac &p) {
        strcpy(ime, p.ime);
        strcpy(prezime, p.prezime);
        strcpy(this->EMBG, p.EMBG);
    }

    ~Potpisuvac() {}

    char *getEMBG() {
        return EMBG;
    }
};

//Да се дефинира класа Dogovor, во која се чуваат информации за:
//
//број на договор (int),
//категорија на договор (низа од 50 знаци),
//поле од 3 потпишувачи на договорот (објекти од класата Potpisuvac)
//Во класата да се додаде метод кој ќе проверува дали постојат два исти потпишувачи (имаат ист ЕМБГ).

class Dogovor {
    //vasiot kod tuka
private:
    int broj;
    char kategorija[50];
    Potpisuvac potpisuvaci[3];

public:
    Dogovor() {

    }

    Dogovor(int broj, char *kategorija, Potpisuvac *potpisuvaci) {
        this->broj = broj;
        strcpy(this->kategorija, kategorija);
        for (int i = 0; i < 3; i++) {
            this->potpisuvaci[i] = potpisuvaci[i];
        }
    }

    Dogovor(const Dogovor &dogovor) {
        broj = dogovor.broj;
        strcpy(kategorija, dogovor.kategorija);
        for (int i = 0; i < 3; i++) {
            potpisuvaci[i] = dogovor.potpisuvaci[i];
        }
    }

    ~Dogovor() {}

    bool proverka() {
        for (int i = 0; i < 3; i++) {
            if (strcmp(potpisuvaci[i].getEMBG(), potpisuvaci[i + 1].getEMBG()) == 0) {
                return true;
            }
        }

        return false;
    }

};

//ne smee da se menuva main funkcijata
int main() {
    char embg[14], ime[20], prezime[20], kategorija[20];
    int broj, n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> embg >> ime >> prezime;
        Potpisuvac p1(ime, prezime, embg);
        cin >> embg >> ime >> prezime;
        Potpisuvac p2(ime, prezime, embg);
        cin >> embg >> ime >> prezime;
        Potpisuvac p3(ime, prezime, embg);
        cin >> broj >> kategorija;
        Potpisuvac p[3];
        p[0] = p1;
        p[1] = p2;
        p[2] = p3;
        Dogovor d(broj, kategorija, p);
        cout << "Dogovor " << broj << ":" << endl;
        if (d.proverka() == true)
            cout << "Postojat potpishuvaci so ist EMBG" << endl;
        else
            cout << "Ne postojat potpishuvaci so ist EMBG" << endl;
    }
    return 0;
}