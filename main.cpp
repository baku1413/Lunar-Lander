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
int x=10; //start pos
int y=10;
const int szerokosc = 80;
const int wysokosc = 40;
bool koniec = false;

int main()
{
    initscr();

    while(c != 27) //ESC = exit
    {
            clear();
            move(y,x);
            refresh();
            printw("A");

            c=getch();
            switch(c)
            {
                case 119://w
                    y--;
                    main();
                break;
                case 97://a
                    x--;
                    main();
                break;
                case 115://s
                    y++;
                    main();
                break;
                case 100://d
                    x++;
                    main();
                break;
                default: break;
            }
    }
    getch();
    opad();
    endwin();
    return 0;




}


void opad()
{
   while(koniec != false)
   {
   y++;
   }
}
