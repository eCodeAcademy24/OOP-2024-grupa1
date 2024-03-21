#include <iostream>

using namespace std;

//За програмски јазик C++.
//
//Да се напише структура која ќе опишува отсечка во дводимензионален простор (две точки). Потоа да се напише функција која ќе проверува дали две отсечки се сечат.

//Input
//-2 -2 2 0
//0 1 1 3
//Output
// 0

//Input
//0 1 2 2
//0 1 1 3
//Output
//1

struct tocka {
    double x;
    double y;
};

struct otsecka {
    tocka t1; // pocetna
    tocka t2; // krajna
};

bool se_secat(otsecka o1, otsecka o2) {
    //otsecka1
    int o1t1x = o1.t1.x; // pocetna tocka x
    int o1t1y = o1.t1.y; // pocetna tocka y
    int o1t2x = o1.t2.x; // krajna tocka x
    int o1t2y = o1.t2.y; // krajna tocka y

    //otsecka2
    int o2t1x = o2.t1.x; // pocetna tocka x
    int o2t1y = o2.t1.y; // pocetna tocka y
    int o2t2x = o2.t2.x; // krajna tocka x
    int o2t2y = o2.t2.y; // krajna tocka y


    if (o1t1x > o2t1x && o1t1x > o2t2x && o1t2x > o2t1x && o1t2x > o2t2x) { //x na o1 se desno od o2
        return false;
    }

    if (o1t1y > o2t1y && o1t1y > o2t2y && o1t2y > o2t1y && o1t2y > o2t2y) { //y na o1 se gore od o2
        return false;
    }

    if (o1t1x < o2t1x && o1t1x < o2t2x && o1t2x < o2t1x && o1t2x < o2t2x) {  //x na o1 se levo od o2
        return false;
    }

    if (o1t1y < o2t1y && o1t1y < o2t2y && o1t2y < o2t1y && o1t2y < o2t2y) { //y na o1 se dole od o2
        return false;
    }

    return true;
}

int main() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    tocka t1 = {x1, y1};
    tocka t2 = {x2, y2};
    otsecka o1 = {t1, t2};
    cin >> x1 >> y1 >> x2 >> y2;
    tocka t3 = {x1, y1};
    tocka t4 = {x2, y2};
    otsecka o2 = {t3, t4};
    cout << se_secat(o1, o2) << endl;
    return 0;
}