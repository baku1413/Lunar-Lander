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





#include <iostream>
#include <ncurses/ncurses.h>
using namespace std;
int c;
int x;
int y;

int main()

{

initscr();
clear();
move(y , x);
printw("%d" , x);
refresh();
c = getch();
while((c = getch()) != KEY_F(1))
	{	switch(c)
		{	case KEY_LEFT:
				x++;

				break;
			case KEY_RIGHT:
				x--;

				break;
			case KEY_UP:
				y++;

				break;
			case KEY_DOWN:
				y--;

				break;
		}
	}

}
