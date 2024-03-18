#include <iostream>

//Од стандарден влез се внесува број n, број на кругови кои ќе се внесуваат, каде 0<n<100. Потоа во наредните n линии се внесуваат x и y
// кои го претставуваат центарот на кругот како и радиусот на кругот. На стандарден излез се печати плоштината и центарот само најголемиот круг
// (со најголема плоштина).
//
//
//
//Напомена: Доколку има повеќе кругови со иста плоштина се печати само првиот круг со таа плоштина.
//
//
//
//Во структурата Точка (Point) треба да се чуваат следните информации:
//
//-x координата (int)
//
//-y координата (int)
//
//
//
//Во структурата Круг (Circle) треба да се чуваат следните информации:
//
//-Центар (Point)
//
//-Радиус (int)

//Input
//3
//1 2 3
//4 5 6
//3 2 3
//Output
//Largest circle has area of: 113.04 with centre: (4,5)
using namespace std;

struct Point {
    int x;
    int y;
};

struct Circle {
    Point point;
    int radius;
};

double areaOfCircle(int radius) {
    return 3.14 * radius * radius;
}

void print(Circle circles[], int n) {
    double maxArea = areaOfCircle(circles[0].radius);
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (maxArea < areaOfCircle(circles[i].radius)) {
            maxArea = areaOfCircle(circles[i].radius);
            index = i;
        }
    }

    cout << "Largest circle has area of: " << maxArea << " with centre: (" << circles[index].point.x << ","
         << circles[index].point.y << ")";
}

int main() {
    Circle circles[100];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> circles[i].point.x >> circles[i].point.y >> circles[i].radius;
    }

    print(circles, n);

    return 0;
}
