#include <iostream>
#include <ncurses/ncurses.h>

using namespace std;

int main()
{
    initscr(); //inicjalizacja

    printw("alfonso kastel gandolfo"); //drukuje na ekranie znaki

    refresh(); //odświeża kappa

    getch(); //czeka na kliknięcie i zwraca integer wciśniętego klawisza

    endwin(); //koniec ncurses

    return 0;
}
