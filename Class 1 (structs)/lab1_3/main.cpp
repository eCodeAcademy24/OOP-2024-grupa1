#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//
//Да се надополни програмата со следните барања:
//
//да се креира структура на точка во тродимензионален простор и да се напише функција која ќе го пресметува растојанието помеѓу две такви точки.
//да се напише функција која како аргумент прима три точки во дводимензионален простор и ќе проверува дали тие точки лежат на иста права.

//Input
//0 1
//2 2
//4 3
//Output
//2.24
//2.45
//1

struct tocka2D {
    float x;
    float y;
};

struct tocka3D {
    float x;
    float y;
    float z;
};

float rastojanie2D(tocka2D t1, tocka2D t2) {
    return sqrt(pow(t1.x - t2.x, 2) + pow(t1.y - t2.y, 2));
}

//да се креира структура на точка во тродимензионален простор и да се напише функција која ќе го пресметува растојанието помеѓу две такви точки.
float rastojanie3D(tocka3D t1, tocka3D t2) {
    return sqrt(pow(t1.x - t2.x, 2) + pow(t1.y - t2.y, 2) + pow(t1.z - t2.z, 2));
}

//да се напише функција која како аргумент прима три точки во дводимензионален простор и ќе проверува дали тие точки лежат на иста права.
int ista_prava(tocka2D t1, tocka2D t2, tocka2D t3) {
    float slope1 = (t1.y - t2.y) / (t1.x - t2.x);
    float slope2 = (t3.y - t2.y) / (t3.x - t2.y);

    if (slope1 == slope2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {

    //0 1
    //2 2
    //4 3

    float x1, y1, x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
//    tocka2D t1; eden nachin
//    t1.x = x1;
//    t1.y = y1;
    tocka2D t1 = {x1, y1};
    tocka2D t2 = {x2, y2};
    cout << fixed << setprecision(2) << rastojanie2D(t1, t2) << endl;
    float z1, z2;
    cin >> z1 >> z2;
    tocka3D t3 = {x1, y1, z1};
    tocka3D t4 = {x2, y2, z2};
    cout << rastojanie3D(t3, t4) << endl;

    tocka2D t5 = {z1, z2};
    cout << ista_prava(t1, t2, t5) << endl;
    return 0;
}
