#include <iostream>
#include <cstring>

using namespace std;

//Да се дефинира класа Film, во која ќе се чуваат информации за:
//
//име низа од 100 знаци
//режисер низа од 50 знаци
//жанр низа од 50 знаци
//година цел број
//Сите променливи треба да бидат приватни. Соодветно во рамките на класата да се дефинираат:
//
//default конструктор и конструктор со аргументи
//метод за печатење на информациите за филмот
//Дополнително да се реализира надворешна функција:
//
//void pecati_po_godina(Film *f, int n, int godina) која ќе прима аргумент низа од филмови,
// вкупниот број на филмови и година, а треба да ги отпечати само филмовите кои се направени во дадената година.

//Input
//4
//Frankenweenie
//Tim_Burton
//Animation
//2012
//Lincoln
//Steven_Spielberg
//History
//2012
//Wall-E
//Andrew_Stanton
//Animation
//2008
//Avatar
//James_Cameron
//Fantasy
//2009
//2008
//Output
//Ime: Wall-E
//Reziser: Andrew_Stanton
//Zanr: Animation
//Godina: 2008




//4
//Frankenweenie
//Tim_Burton
//Animation
//2012
//Lincoln
//Steven_Spielberg
//History
//2012
//Wall-E
//Andrew_Stanton
//Animation
//2008
//Avatar
//James_Cameron
//Fantasy
//2009
//2008


class Film {
//име низа од 100 знаци
//режисер низа од 50 знаци
//жанр низа од 50 знаци
//година цел број
private:
    char name[100];
    char director[50];
    char genre[50];
    int year;
public:
    Film() {

    }

    Film(char *name, char *director, char *genre, int year) {
        strcpy(this->name, name);
        strcpy(this->director, director);
        strcpy(this->genre, genre);
        this->year = year;
    }

    //TODO: get and set methods
    int getYear() {
        return year;
    }

    void print() {
        //Ime: Wall-E
        cout << "Ime: " << name << endl;

        //Reziser: Andrew_Stanton
        cout << "Reziser: " << director << endl;

        //Zanr: Animation
        cout << "Zanr: " << genre << endl;

        //Godina: 2008
        cout << "Godina: " << year << endl;
    }
};

//void pecati_po_godina(Film *f, int n, int godina) која ќе прима аргумент низа од филмови,
// вкупниот број на филмови и година, а треба да ги отпечати само филмовите кои се направени во дадената година.

void pecati_po_godina(Film f[], int n, int godina) {
    for (int i = 0; i < n; i++) {
        if (f[i].getYear() == godina) {
            f[i].print();
        }
    }
}

//4
//Frankenweenie --> name
//Tim_Burton --> director
//Animation --> genre
//2012 --> year
//Lincoln
//Steven_Spielberg
//History
//2012
//Wall-E
//Andrew_Stanton
//Animation
//2008
//Avatar
//James_Cameron
//Fantasy
//2009
//2008
int main() {
    int numFilms;
    cin >> numFilms;

    Film films[numFilms];

    for (int i = 0; i < numFilms; i++) {
        char name[100];
        char director[50];
        char genre[50];
        int year;
        cin >> name >> director >> genre >> year;

        films[i] = Film(name, director, genre, year);
    }

    int godina;
    cin >> godina;

    pecati_po_godina(films, numFilms, godina);

    return 0;
}
