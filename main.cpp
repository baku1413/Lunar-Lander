#include <iostream>
#include <ncurses/ncurses.h>

using namespace std;
char c=0;
int main()
{
    initscr(); //inicjalizacja

    printw("alfonso kastel gandolfo"); //drukuje na ekranie znaki

    c = getch();

    printw("%d" , c);

    refresh(); //odswieza kappa

    getch(); //czeka na klikni�cie i zwraca integer wci�ni�tego klawisza
    main();
    endwin(); //koniec ncurses

    return 0;
}
