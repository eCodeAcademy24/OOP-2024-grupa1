#include <iostream>

using namespace std;

//За програмски јазик C.
//
//Да се напише структура која ќе опишува отсечка во дводимензионален простор (две точки). Потоа да се напише функција која ќе проверува дали две отсечки се сечат.

//Input
//-2 -2 2 0
//0 1 1 3
//Output
// 0

typedef struct tocka {
    double x;
    double y;
} tocka;

typedef struct otsecka {
    tocka t1;
    tocka t2;
} otsecka;

bool na_ista_prava(tocka p, tocka q, tocka r) {
    float slope1 = (q.y - p.y) / (q.x - p.x);
    float slope2 = (r.y - q.y) / (r.x - q.x);

    return slope1 == slope2;
}

int orientation(tocka p, tocka q, tocka r) {
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0; // Колинеарни
    return (val > 0) ? 1 : 2; // 1 за clockwise, 2 за counterclockwise
}

int se_secat(otsecka o1, otsecka o2) {
    tocka p1 = o1.t1;
    tocka q1 = o1.t2;
    tocka p2 = o2.t1;
    tocka q2 = o2.t2;

    if (na_ista_prava(p1, q1, p2) && na_ista_prava(p1, q1, q2)) {
        return false;
    }

    // Одредување на ориентациите за секоја комбинација од три точки
    int o1o2 = orientation(p1, q1, p2);
    int o3o4 = orientation(p1, q1, q2);
    int o4o1 = orientation(p2, q2, p1);
    int o2o3 = orientation(p2, q2, q1);

    // Генерален случај
    if (o1o2 != o3o4 && o4o1 != o2o3)
        return true;

    // Специјални случаи
    // p1, q1 и p2 се колинеарни и p2 лежи на отсечката p1q1
    if (o1o2 == 0 && na_ista_prava(p1, p2, q1))
        return true;

    // p1, q1 и q2 се колинеарни и q2 лежи на отсечката p1q1
    if (o3o4 == 0 && na_ista_prava(p1, q2, q1))
        return true;

    // p2, q2 и p1 се колинеарни и p1 лежи на отсечката p2q2
    if (o4o1 == 0 && na_ista_prava(p2, p1, q2))
        return true;

    // p2, q2 и q1 се колинеарни и q1 лежи на отсечката p2q2
    if (o2o3 == 0 && na_ista_prava(p2, q1, q2))
        return true;

    // Сите останати случаи не се пресекуваат
    return false;
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