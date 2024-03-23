#include <iostream>

using namespace std;
//Да се дефинира класа Krug, во која се чуваат информации за:
//
//радиус float
//бројот π const float.
//Во класата да се реализираат:
//
//default конструктор и конструктор со аргументи
//метод за пресметување плоштина
//метод за пресметување периметар
//метод кој кажува дали плоштината и периметарот на даден круг се еднакви

//Input
//15
//Output
//94.2
//706.5
//0

class Krug {
private:
    float radius;
    const float pi = 3.14;

public:
    Krug() {}

    Krug(float radius) {
        this->radius = radius;
    }

    float getRadius() {
        return radius;
    }

    void setRadius(float radius) {
        this->radius = radius;
    }

    //метод за пресметување периметар
    float perimetar() {
        float l = 2 * pi * radius;
        return l;
    }

    //метод за пресметување плоштина
    float plostina() {
        return pi * radius * radius;
    }

    //метод кој кажува дали плоштината и периметарот на даден круг се еднакви
    bool ednakvi() {
        if (this->plostina() == this->perimetar())
            return true;

        return false;
    }
};

int main() {
    float r;
    cin >> r;
    //instanciraj objekt od klasata Krug cij radius e vrednosta procitana od tastatura
    Krug k(r);
    cout << k.perimetar() << endl;
    cout << k.plostina() << endl;
    cout << k.ednakvi() << endl;
    //instanciraj objekt od klasata Krug cij radius ne e definiran
    Krug krug;
    return 0;
}