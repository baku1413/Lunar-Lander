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

    getch(); //czeka na klikniêcie i zwraca integer wciœniêtego klawisza
    main();
    endwin(); //koniec ncurses

    return 0;
}
