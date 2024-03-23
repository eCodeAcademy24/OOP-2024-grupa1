#include <iostream>
#include <cstring>
//Да се дефинира класа Agol, во која се чуваат информации за:
//
//степени, минути и секунди (int)
//Во класата да се реализираат:
//
//конструктор по потреба
//методи за поставување на вредности на атрибутите на класата (set методи)
//метод за пресметување на вредноста на аголот во секунди
//Да се дефинира и метод за проверување на тоа дали внесениот агол е валиден,
// односно дали се внесени соодветни вредности за атрибутите (во границите кои ги дозволуваат).
//Input
//15 20 20
//Output
// 55220

//Input
//380 80 0
//Output
//Nevalidni vrednosti za agol
using namespace std;

class Agol {
private:
    int stepeni;
    int minuti;
    int sekundi;

public:
    Agol() {}

    Agol(int stepeni, int minuti, int sekundi) {
        this->stepeni = stepeni;
        this->minuti = minuti;
        this->sekundi = sekundi;
    }

    int getStepeni() {
        return stepeni;
    }

    int getMinuti() {
        return minuti;
    }

    int getSekundi() {
        return sekundi;
    }

    void set_stepeni(int stepeni) {
        this->stepeni = stepeni;
    }

    void set_minuti(int min) {
        minuti = min;
    }

    void set_sekundi(int sekundi) {
        this->sekundi = sekundi;
    }

    int to_sekundi() {
        int vkupno = sekundi + minuti * 60 + stepeni * 3600;
        return vkupno;
    }
};

bool proveri(int deg, int min, int sec) {
    if (deg > 360 || deg < 0) {
        return false;
    }

    if (min > 60 || min < 0) {
        return false;
    }

    if (sec > 60 || sec < 0) {
        return false;
    }

    return true;

}

bool changeOfSeconds(Agol a, int sec) {
    return a.getSekundi() != sec;
}


int main() {
    //da se instancira objekt od klasata Agol
    Agol a1;
    int deg, min, sec;
    cin >> deg >> min >> sec;

    if (proveri(deg, min, sec)) {

        a1.set_stepeni(deg);
        a1.set_minuti(min);
        a1.set_sekundi(sec);
        cout << a1.to_sekundi();
        if (changeOfSeconds(a1, sec))
            cout << "Ne smeete da gi menuvate sekundite vo ramkite na klasata!" << endl;

    } else {
        cout << "Nevalidni vrednosti za agol";
    }

    return 0;
}
