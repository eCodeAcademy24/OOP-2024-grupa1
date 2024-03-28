#include <iostream>

using namespace std;

//Да се креира структура Igrac во која се чуваат податоци за еден играч на компјутерската игра.
// За играчот се чуваат информации за корисничкото име на играчот (низа од 15 знаци),
// број на ниво до кој играчот е стигнат (цел број) и број на освоени поени (цел број) (10 поени).
//
//Потоа да се креирa структура KompjuterskaIgra во која се чуваат податоци за името на играта (низа од 20 знаци),
// низа од играчи кои ја играат играта (најмногу 30) и бројот на играчи. (10 поени)
//
//Треба да се направи функција со потпис (15 поени)
//
//void najdobarIgrac(KompjuterskaIgra *lista, int n)
//Оваа функција треба да го испечати името на најдобриот играч на онаа игра која има најголема популарност
// (ја играат наjголем број на играчи). Најдобар играч е играчот кој има најголем број на освоени поени.
// Ако има повеќе играчи со ист максимален број на освоени поени, најдобар е играчот кој има достигнато најголемо ниво.
//
//Печатењето е во форматот: "Najdobar igrac e igracot so korisnicko ime XXXXX koj ja igra igrata YYYYYY".
// (XXXXXX е корисничкото име на најдобриот играч,а YYYYY е името на играта која ја играат најголем број на играчи)
//
//(Забелешка: секогаш ќе има точно еден најдобар играч)


struct Player {
    char username[15];
    int level;
    int points;
};

struct Game {
    char name[20];
    Player players[30];
    int numPlayers;
};


//Оваа функција треба да го испечати името на најдобриот играч на онаа игра која има најголема популарност
// (ја играат наjголем број на играчи). Најдобар играч е играчот кој има најголем број на освоени поени.
// Ако има повеќе играчи со ист максимален број на освоени поени, најдобар е играчот кој има достигнато најголемо ниво.
void najdobarIgrac(Game *games, int numGames) {
    int maxNumPlayers = games[0].numPlayers;
    Game popularGame = games[0];

    for (int i = 1; i < numGames; i++) {
        if (maxNumPlayers < games[i].numPlayers) {
            maxNumPlayers = games[i].numPlayers;
            popularGame = games[i];
        }
    }

    int maxPoints = popularGame.players[0].points;
    int maxLevel = popularGame.players[0].level;
    Player MVP = popularGame.players[0];

    for (int i = 1; i < popularGame.numPlayers; i++) {
        if (maxPoints < popularGame.players[i].points) {
            maxPoints = popularGame.players[i].points;
            maxLevel = popularGame.players[i].level;
            MVP = popularGame.players[i];
        } else if (maxPoints == popularGame.players[i].points) {
            if (maxLevel < popularGame.players[i].level) {
                maxLevel = popularGame.players[i].level;
                maxPoints = popularGame.players[i].points;
                MVP = popularGame.players[i];
            }
        }
    }

    //Najdobar igrac e igracot so korisnicko ime fikjo koj ja igra igrata Cars
    cout << "Najdobar igrac e igracot so korisnicko ime " << MVP.username << " koj ja igra igrata " << popularGame.name;

}

//Input
//2
//Snake
//2
//user1 5 120
//user2 4 120
//Cars
//3
//koliubavi 5 130
//fikjo 3 150
//motor 4 140
int main() {
    int numGames;
    cin >> numGames;

    Game games[numGames];

    for (int i = 0; i < numGames; i++) {
        cin >> games[i].name;
        cin >> games[i].numPlayers;

        for (int j = 0; j < games[i].numPlayers; j++) {
            cin >> games[i].players[j].username;
            cin >> games[i].players[j].level;
            cin >> games[i].players[j].points;
        }
    }

    najdobarIgrac(games, numGames);
    return 0;
}
