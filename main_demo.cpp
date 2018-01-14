#include "main_gra.h"
#include "drawing.h"
#include "cpp11_utils.h"
#include <cstdlib>
#include <iostream>
#include <ncurses/ncurses.h>
#include <string>
#include <windows.h>
#include <iostream>
#include <ctime>



/*! \brief demo gry
 * statek z litery A ma spasc na zmiemie i zostac rozbity
 *
 * \param dy - pozycja y statku w demie
 * \param dx - pozycja x statku w demie
 * \param d - kolejne iteracje petli dema
 * \param demo - zmienna boolean czy demo aktualnie sie toczy
 * \param time_delta - sta³a czasowa ustajalaca "framerate" jak szybko dziala program
 * \param start - czas pobierany z funkcji TimeMs()
 * \param now - czas
 * \param delta - czas jaki uplynal od teraz czyli czas zmierzony wczesniej-czas teraz
 *
 * \return
 *
 */



int dy = 1;
int dx = 10;
int d=0;
int e=0;
bool demo =true;


    int main_demo()
{
    srand(time(NULL));
    initscr();
    refresh();
    const double time_delta = 1.0/15;
    double start = Cpp11::TimeMs();
    mvprintw(dy,dx,"A");
    mvprintw(36, 15, "|____|");
    refresh();
        while(demo)
        {
        srand(time(NULL));
        clear();
        mvprintw(36, 15, "|____|");
        double now = Cpp11::TimeMs();
        double delta = now - start;
        if (delta < time_delta * 1000) {
            Cpp11::SleepMs(time_delta * 1000 - delta);
        }
        now = Cpp11::TimeMs();
        delta = (now - start) / 1000;
        start = now;

            mvprintw(dy,dx,"A");
            refresh();
            dy++;
            dx++;



    while(d<80)
    {
        d=d+1;
        refresh();
        mvprintw(37, d, "-");
    }

if (dy>37)
{

    mvprintw(19,30, "STATEK ROZBITY");
    mvprintw(22,34, "DEMO");
    refresh();
    Sleep(1000);
    dx=( rand () % 2) + 30;
    dy=1;
    break;
}


}
endwin();
return 0;
}
