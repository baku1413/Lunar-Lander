
#include "main.h"
#include "main_gra.h"
#include "drawing.h"
#include "cpp11_utils.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ncurses/ncurses.h>
#include <string>
#include <cstring>
#include <ctime>
#include <windows.h>

using namespace std;
/* DEKLARACJA ZMIENNYCH */
int c=0;                //wcisniety klawisz
int x=(rand()%79) + 1;  //pozycja x
int y=0;                //pozycja y
int moc = 0;            //moc statku
int ground_level = 0;   //poziom podloza
int score;              //wynik
int platformax=10;      //pozycja platformy x
int platformay=10;      //pozycja platformy y


string imie;            //imie gracza
string pomyslnosc = "  STATEK ROZBITY"; //pomyslnosc zadania gracza

bool graa = true;       //zmienna czy gra jest w trakcie


/*! \brief Koniec gry
 *
 *  jesli nastapi przerwanie petli programu
 *  program ma zapytac o Nick oraz zapisać go wraz z wynikiem do pliku
 *
 *  \param imie - nick gracza
 *  \param score - wynik uzyskany przez gracza
 *
 */
void koniec_gry(string imie, int score)
{
 fstream wyniki;
 wyniki.open("HOF.txt", ios::out | ios::app);
 printf("Podaj Nick: ");
 cin >> imie;
 wyniki<<imie;
 wyniki<<"  twoj wynik:";

 wyniki<<score;
 wyniki<<pomyslnosc<<endl;
 score==0;
 wyniki.close();
}

/*! \brief Wyświetla ekran rozbicia statku
 *
 *  jesli predkosc statku podczas ladowania jest wieksza lub równa 5 jednostek
 *  wyswietlony ma zostac ekran z odpowiednim napisem i instrukcją
 *
 */
void statek_rozbity()
{
mvprintw(19,30, "STATEK ROZBITY");
mvprintw(22,32, "NACISNIJ Q");
}

/** \brief głowna funckja gry
 *
 *  funkcja ta odpowiada za wyswietlanie wyniku wykrywanie kolizji z podlozem rysowanie platformy odczyt wcisnietych klawiszy itp
 *  to glowny czlon programu
 *
 * \param ship_thrust - aktualna moc napedu
 * \param ship_position_y - pozycja y statku = parametrowi y
 * \param ship_velocity - predkosc statku
 * \param gravity - wartosc grawitacji znak na sek^2
 * \param time_delta - stała czasowa ustajalaca "framerate" jak szybko dziala program
 * \param start - czas pobierany z funkcji TimeMs()
 * \param ground_level - poziom podloza do ladowania
 * \param platformax - polozenie platformy x
 * \param platformay- polozenie platformy y
 * \param graa - zmienna boolean true jesli gra sie toczy
 * \param c - zmienna przechowujaca wcisniety klawisz
 * \param now - czas
 * \param delta - czas jaki uplynal od teraz czyli czas zmierzony wczesniej-czas teraz
 * \param y - pozycja statku y
 * \param x - poyzcja statku x
 * \param score - wynik gracza
 * \param pomyslnosc - zmienna string ma za zadanie przechowac pomyslonsc wykoannego zadania i byc wpisana do wyniku koncowego
 *
 *\return
 *
 */

int main_gra()
{
    graa=true;
    //rysuj_podloze(ground_level);
    fstream wyniki;
    // dane statku
    double ship_thrust = 0; // moc silinka
    double ship_position_y = 0; //pozycja statku y
    double ship_velocity = 0;   // prędkośći statku
    // ustawienia planety
    const double gravity = 2; // grawitacja znak na sekunde^2


    const double time_delta = 1.0/60;

    initscr();
    curs_set(0);
    noecho();
    raw();
    nodelay(stdscr, true);
    clear();

    double start = Cpp11::TimeMs();
    srand(time(NULL));
    ground_level=( rand () % 38) + 20;
    platformax=(rand()%72);     //platformay=(rand()%30) + 35;

    while(graa)
   {
       c = getch();


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
            ship_thrust=0;
            ship_velocity=0;
            draw_ship(x, y, ship_thrust);
        }


        if (y >= 0 && y <= 40) {

            mvprintw(0,32, "Wynik: %d",score);
            /*
            mvprintw(1,72, "DEBUG:");
            mvprintw(2,72, "X: %d",x);
            mvprintw(3,72, "y: %d",y);
            mvprintw(4,72, "plX: %d",platformax);
            mvprintw(5,72, "ply: %d",platformay);
            */
            mvprintw(1,59, "szybkosc: %f",ship_velocity);
            mvprintw(2,59, "moc statku: %f",ship_thrust);
            //mvprintw(8,60, "delta: %f",delta);
            draw_ship(x, y, ship_thrust);
        }

       int ground_level = 37;

        score=score+ship_thrust;
        mvprintw(ground_level-1, platformax, "|____|");



        /**< generowanie terenu
         *   pętla for inicjuje zmienna i=0 , wykonuje ja do czasu kiedy bedzie ona mniejsza od 80 nastepnie inkrementuje po kazdym wykonaniu instrukjcji
         */
        for (int i = 0; i < 80; i=i+1)
        {
            mvprintw(ground_level, i, "-");
            if(i==79) break;
        }
        /**< detekcja predkosci i jesli jest zbyt duza to czysci ekran i wykonuje funkcje statek_rozbity */
        if (y>=37 && ship_velocity>=5)
        {
            clear();
            pomyslnosc = " STATEK ROZBITY";
            statek_rozbity();
        }
        /**< jesli ladowanie bylo wykonane z odpowiednia predkoscia i w odpowiednim miejscu to odpowiednio zmmniejsza wynik */
        if (y >= 37 && ship_velocity<5) {
            if (x==platformax+1 || x==platformax+2 || x==platformax+3 || x==platformax+4)
            {
                score=score/100;
                clear();
                mvprintw(19,25, "WYLADOWANO NA PLATFORMIE WYNIK ZMNIEJSZONY");
                refresh();
                Sleep(5000);
                pomyslnosc = " POMYSLNE LADOWANIE";

                break;
            }
            pomyslnosc = " POMYSLNE LADOWANIE";
            break;
        }



/** \brief sterowanie statkiem
 *
 * \param c - wcisniety klawisz
 * \param ship_thrust - moc napedu
 * \param score - wynik gracza
 *
 */
                switch(c)
            {
                case 'w':
                    ship_thrust = ship_thrust + 0.2;

                    break;
                case 97://a
                    x--;
                    score=score+100;

                    break;
                case 115://s
                    ship_thrust = ship_thrust - 0.2;
                    ship_thrust = max(0.0, ship_thrust);       //naped nie mniejszy od zera
                    break;
                case 100://d
                    x++;
                    score=score+100;
                    break;
                case 'q':

                    graa = false;

                    break;
                default: break;
            }


        refresh();


    }
            endwin();
            koniec_gry(imie, score);

    return 0;


}

/** \brief Rysowanie statku na ekranie wraz z jego napedem
 *
 *             mala moc: '
 *      wieksza niz mala: v
 *           srednia moc: V
 *              duza moc: W
 *           ogromna moc: W
 *                        V
 *
 * \param thrust - moc napedu
 * \param x - pozycja x
 * \param y - pozycja y statku
 * \return
 *
 */

void draw_ship(int x, int y, double thrust) {
    mvprintw(y+0, x+0, "A");

    // mala moc '
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
