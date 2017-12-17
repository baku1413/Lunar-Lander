/*

    initscr(); //inicjalizacja
    clear();  //czysci ekran
    printw("alfonso kastel gandolfo"); //drukuje na ekranie znaki

    move(y , x);

    c = getch();    //char c = nacisniety klawisz

    printw("%d" , c);  //%d to parametr nie wiem jeszcze jaki //drukuje zawartość chara (c)

    x++;
    y++;

    refresh(); //odswieza kappa

    getch(); //czeka na klikniêcie i zwraca integer wciœniêtego klawisza
    main();
    endwin(); //koniec ncurses

    return 0; */

#include "main_gra.h"
#include "drawing.h"
#include "cpp11_utils.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ncurses/ncurses.h>
#include <string>
#include <cstring>

using namespace std;
int c=0;
int x=10; //start pos
int y=0;
int moc = 0;
int ground_level = 37;
string imie;
string score;
int lol = 1;
int platformax=10;
int platformay=10;
int wynik=0;


const int platforma_wysokosc = 1;
const char *face[] = {
    "|____|"
};

bool graa = true;

/* Funkcja pytająca o imie gracza a następnie dopisująca jego uzyskany wynik
zapisuje to potem na dysku w pliku HOF.txt */

void koniec_gry(string imie, string score)
{
 clear();
 fstream wyniki;
 wyniki.open("HOF.txt", ios::out | ios::app);
 move(0,0);
 printw("Podaj Nick");
 cin>>imie;
 wyniki<<imie;
 wyniki<<"  twoj wynik:";
 wyniki<<score<<endl;
 wyniki.close();
 main();
}

/*
void rysuj_podloze(int ground_level)
{

        for (int i = 0; i < 80; i=i+1)
        {
            ground_level=37;
            mvprintw(ground_level, i, "=");
            ground_level=( rand () % 36) + 35;

        }
return;
}
*/


int main_gra()
{
    //rysuj_podloze(ground_level);
    fstream wyniki;
    // dane statku
    double ship_thrust = 0; // moc silinka
    double ship_position_y = 0; //pozycja statku y
    double ship_velocity = 0;   // prędkośći statku
    // ustawienia planety
    const double gravity = 0.9; // grawitacja znak na sekunde^2

    // ustawienia wyswietlania
    const double time_delta = 1.0/60;

    initscr();

    curs_set(0);
    noecho();
    raw();
    nodelay(stdscr, true);

    clear();


    double start = Cpp11::TimeMs();
    while(graa)
    {
        double now = Cpp11::TimeMs();
        double delta = now - start;
        if (delta < time_delta * 1000) {
            Cpp11::SleepMs(time_delta * 1000 - delta);
        }
        now = Cpp11::TimeMs();
        delta = (now - start) / 1000;
        start = now;


        ship_velocity =
            ship_velocity                               // predkosc aktualna
            + gravity * delta                      // sila grawitacji
            - ship_thrust * delta;                  // predkosc z silnika
        ship_position_y =
            ship_position_y
            + ship_velocity * delta;

        // opadanie statku
        y = (int)ship_position_y;


        clear();

        // ograniczenie wyswietlania statku
        if (y<=-1) {
            y=0;
            draw_ship(x, y, ship_thrust);
        }

        if (y >= 0 && y <= 40) {


            draw_ship(x, y, ship_thrust);
        }

        int ground_level = 37;

        if (y == platformay && x == platformax)
        {
        wynik++;
        score = to_string(wynik);

        }


while (lol == 1)
{
        platformay=(rand()%20) + 25;
        platformax=(rand()%80);
        lol = 0;
}


        mvprintw(0,72, "Wynik: %d",wynik);
        mvprintw(platformay, platformax, "|____|");



        for (int i = 0; i < 80; i=i+1)
        {

            mvprintw(ground_level, i, "=");
            ground_level=( rand () % 36) + 35;
            platformay=(rand()%20) + 25;
            platformax=(rand()%80);


        }

        if (y >= 37) {
            koniec_gry(imie, score);
        }






            switch(c)
            {
                case 'w': // dokladnie to samo co 119://w
                    ship_thrust = ship_thrust + 0.2;

                    break;
                case 97://a
                    x--;

                    break;
                case 115://s
                    ship_thrust = ship_thrust - 0.2;
                    ship_thrust = max(0.0, ship_thrust);
                    break;
                case 100://d
                    x++;
                    break;
                case 'q':

                    graa = false;

                    break;
                default: break;
            }

       // move(40-1, 80-1);
        refresh();
        c = getch(); // nobreak - jesli nic nie nacisnieto to c == ERR

    }
    //getch();




    return 0;


}

void draw_ship(int x, int y, double thrust) {
    mvprintw(y+0, x+0, "A");

    // mala moc
    // wiekasza niz mala v
    // srednia moc V
    // duza moc W
    // ogromna moc W
    //             V
    if (thrust > 0 && thrust < 0.5) {
        mvprintw(++y, x, "'");
    } else if (thrust >= 0.5 && thrust < 1) {
        mvprintw(++y, x, "v");
    } else if (thrust >= 1 && thrust < 1.5) {
        mvprintw(++y, x, "V");
    } else if (thrust >= 1.5) {
        mvprintw(++y, x, "W");
        if (thrust > 2) {
            mvprintw(++y, x, "V");
        }
    }
}
