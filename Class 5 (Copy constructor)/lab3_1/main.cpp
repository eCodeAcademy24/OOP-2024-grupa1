#include <iostream>
#include <cstring>

using namespace std;
//Во оваа задача треба да се внесат и испечатат податоци за автомобили.
//
//За еден автомобил (објект од класата Car) се чуваат следниве податоци:
//
//сопственик (објект од класата Person)
//датум на купување (објект од класата Date)
//цена (float price), предодредена вредност 0
//За класата Car потребно е да се напише метод за печатење print() и метод за добивање на цената getPrice().
//
//Класата Date содржи три цели броеви (int year, month, day) кои претставуваат датум. За неа треба да се напише метод за печатење print(),
// предодреден (default) конструктор, конструктор со параметри и конструктор за копирање.
//
//Класата Person содржи име и презиме (низи од максимум 20 знаци, со предодредени вредности not specified), предодреден конструктор,
// конструктор со параметри и метод за печатење print().
//
//Методот за печатење кај класата Person изгледа вака: [name] [lastName].
//
//Методот за печатење кај класата Date изгледа вака: [year].[month].[day].
//
//Методот за печатење кај класата Car изгледа вака:
//
//owner.print()
//
//date.print()
//
//Price: [price]
//
//Покрај тоа, потребно е да се напише метод cheaperThan(Car* cars, int numCars, float price) кој ќе ги
// испечати сите објекти Car од низата cars со големина numCars чија цена е помала од price.

//Input
//2
//Petre
//Petreski
//2018
//07
//31
//410020
//Output
//Petre Petreski
//2018.7.31
//Price: 410020

//Input
//3
//3
//Riste
//Risteski
//2019
//12
//12
//230000
//Petre
//Petreski
//2018
//07
//31
//410020
//Trajche
//Trajcheski
//2017
//03
//07
//575000
//300000
//Output
//Riste Risteski
//2019.12.12
//Price: 230000

//Input
//1
//Riste
//Risteski
//2019
//12
//12
//230000
//Output
//Riste Risteski
//2019.12.12
//Price: 230000


class Person {
private:
    char name[20];
    char surname[20];
public:
    Person() {
        strcpy(name, "not specified");
        strcpy(this->surname, "not specified");
    }

    Person(char *name, char *surname) {
        strcpy(this->name, name);
        strcpy(this->surname, surname);
    }

    Person(const Person &person) {
        strcpy(name, person.name);
        strcpy(surname, person.surname);
    }

    ~Person() {}


    //Методот за печатење кај класата Person изгледа вака: [name] [lastName].
    void print() {
        cout << name << " " << surname << endl;
    }

};


class Date {
private:
    int year;
    int month;
    int day;
public:
    Date() {}

    Date(int year, int month, int day) {
        this->year = year;
        this->month = month;
        this->day = day;
    }

    Date(const Date &date) {
        this->year = date.year;
        this->month = date.month;
        this->day = date.day;
    }

    ~Date() {

    }

    //Методот за печатење кај класата Date изгледа вака: [year].[month].[day].
    void print() {
        cout << year << "." << month << "." << day << endl;
    }
};

class Car {
private:
    Person owner;
    Date date;
    float price;
public:
    Car() {
        price = 0;
    }

    Car(Person owner, Date date, float price) {
        this->owner = owner;
        this->date = date;
        this->price = price;
    }

    Car(const Car &car) {
        owner = car.owner;
        date = car.date;
        price = car.price;
    }

    ~Car() {}

    float getPrice() {
        return price;
    }

    //Методот за печатење кај класата Car изгледа вака:
//
//owner.print()
//
//date.print()
//
//Price: [price]
    void print() {
        owner.print();
        date.print();
        cout << "Price: " << price;
    }
};

//Покрај тоа, потребно е да се напише метод cheaperThan(Car* cars, int numCars, float price) кој ќе ги
// испечати сите објекти Car од низата cars со големина numCars чија цена е помала од price.
void cheaperThan(Car *cars, int numCars, float price) {
    for (int i = 0; i < numCars; i++) {
        if (cars[i].getPrice() < price) {
            cars[i].print();
        }
    }
}

int main() {
    char name[20];
    char lastName[20];
    int year;
    int month;
    int day;
    float price;

    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cin >> name;
        cin >> lastName;
        Person lik(name, lastName);

        cin >> year;
        cin >> month;
        cin >> day;
        Date date(year, month, day);

        cin >> price;
        Car car(lik, date, price);

        car.print();
    } else if (testCase == 2) {
        cin >> name;
        cin >> lastName;
        Person lik(name, lastName);

        cin >> year;
        cin >> month;
        cin >> day;

        Date date(Date(year, month, day));

        cin >> price;
        Car car(lik, date, price);
        car.print();
    } else {
        int numCars;
        cin >> numCars;

        Car cars[10];
        for (int i = 0; i < numCars; i++) {
            cin >> name;
            cin >> lastName;
            Person lik(name, lastName);

            cin >> year;
            cin >> month;
            cin >> day;
            Date date(year, month, day);

            cin >> price;
            Car car(lik, date, price);
            cars[i] = car;
            //cars[i] = Car(lik, date, price); mozhe i vaka
        }
        float priceLimit;
        cin >> priceLimit;
        cheaperThan(cars, numCars, priceLimit);
    }

    return 0;
}
