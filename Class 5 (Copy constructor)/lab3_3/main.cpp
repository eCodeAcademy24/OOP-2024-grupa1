#include<iostream>
#include<cstring>

using namespace std;

//Во оваа задача потребно е да се внесат податоци за насловна страница на списание.
//
//За претставување на насловната страница напишете класа FrontPage која ќе содржи:
//
//објект од класата NewsArticle која ја претставува насловната вест на страницата
//цена (float price) со предодредена вредност 0
//број на издание на списанието (int editionNumber) со предодредена вредност 0
//За класата FrontPage напишете предодреден (default) конструктор и конструктор со параметри. Класата NewsArticle треба да содржи:
//
//објект од класата Category која ја претставува категоријата во која спаѓа веста
//наслов од максимум 30 знаци (char title[30]) со предодредена вредност untitled
//За класата NewsArticle напишете предодреден конструктор и конструктор со параметри.
//
//Класата Category треба да содржи име од максимум 20 знаци (char name[20]) со предодредена вредност unnamed.
//
//За сите класи треба да напишете соодветен метод за печатење print().
//
//Внимајте на редоследот на параметрите во конструкторите. Не го менувајте main методот.
//
//За категоријата се печати само името: Category: [name].
//
//За веста се печати насловот, па категоријата во нов ред:
//
//Title: [title]
//
//category.print()
//
//За насловната страница се печати цената и изданието во прв ред, па веста во втор:
//
//Price: [price], Edition number: [editionNumber]
//
//article.print()

class Category {
private:
    char name[20];
public:

    Category() {
        strcpy(name, "untitled");
    }

    Category(char *name) {
        strcpy(this->name, name);
    }

    //За категоријата се печати само името: Category: [name].
    void print() {
        cout << "Category: " << name << endl;
    }
};

class NewsArticle {
private:
    Category category;
    char title[30];
public:
    NewsArticle() {
        strcpy(title, "untitled");
    }

    NewsArticle(Category category) {
        this->category = category;
        strcpy(title, "untitled");
    }

    NewsArticle(Category category, char *title) {
        this->category = category;
        strcpy(this->title, title);
    }

    //За веста се печати насловот, па категоријата во нов ред:
    //Title: [title]
    //category.print()
    void print() {
        cout << "Title: " << title << endl;
        category.print();
    }
};

class FrontPage {
private:
    NewsArticle article;
    float price;
    int editionNumber;
public:
    FrontPage() {
        price = 0;
        editionNumber = 0;
    }

    FrontPage(NewsArticle article) {
        this->article = article;
        price = 0;
        editionNumber = 0;
    }

    FrontPage(NewsArticle article, float price) {
        this->article = article;
        this->price = price;
        editionNumber = 0;
    }

    FrontPage(NewsArticle article, float price, int editionNumber) {
        this->article = article;
        this->price = price;
        this->editionNumber = editionNumber;
    }

    //За насловната страница се печати цената и изданието во прв ред, па веста во втор:
    //Price: [price], Edition number: [editionNumber]
    //article.print()
    void print() {
        cout << "Price: " << price << ", Edition number: " << editionNumber << endl;
        article.print();
    }
};

//Input
//2
//sport
//120
//2
//Output
//Price: 120, Edition number: 2
//Title: untitled
//Category: sport

//Input
//4
//Output
//Price: 0, Edition number: 0
//Article title: untitled
//Category: unnamed

//Input
//1
//2
//sport
//MKD-SLO_1:1
//120
//2
//edukativno
//FINKI_dobi_zgrada
//101
//10
//Output
//Price: 120, Edition number: 2
//Article title: MKD-SLO_1:1
//Category: sport
//Price: 101, Edition number: 10
//Article title: FINKI_dobi_zgrada
//Category: edukativno

//Input
//
//3
//edukativno
//FINKI_dobi_zgrada
//320.2
//Output
//Price: 320.2, Edition number: 0
//Article title: FINKI_dobi_zgrada
//Category: edukativno
int main() {
    char categoryName[20];
    char articleTitle[30];
    float price;
    int editionNumber;

    int testCase;
    cin >> testCase;


    if (testCase == 1) {
        int iter;
        cin >> iter;
        while (iter > 0) {
            cin >> categoryName;
            cin >> articleTitle;
            cin >> price;
            cin >> editionNumber;
            Category category(categoryName);
            NewsArticle article(category, articleTitle);
            FrontPage frontPage(article, price, editionNumber);
            frontPage.print();
            iter--;
        }
    } else if (testCase == 2) {
        cin >> categoryName;
        cin >> price;
        cin >> editionNumber;
        Category category(categoryName);
        NewsArticle article(category);
        FrontPage frontPage(article, price, editionNumber);
        frontPage.print();
    }// test case 3
    else if (testCase == 3) {
        cin >> categoryName;
        cin >> articleTitle;
        cin >> price;
        Category category(categoryName);
        NewsArticle article(category, articleTitle);
        FrontPage frontPage(article, price);
        frontPage.print();
    } else {
        FrontPage frontPage = FrontPage();
        frontPage.print();
    }
    return 0;
}
