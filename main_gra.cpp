/*







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
#include <string>

using namespace std;
int c=0;
int x=10; //start pos
int y=0;
int moc = 0;
string naped;
bool graa = true;

int main_gra()
{

            initscr();

            curs_set(0);
            noecho();


            clear();

    while(c != 27) //ESC = exit
    {
        if (moc > 3)
            {
                moc = 0;
            }
        c=getch();

            clear();
            move(y,x);
            printw("A");
            move(y+1, x);
            printw("%s", naped.c_str());
            move(y+1, x+1);


            if (moc == 0)
            {
                naped="";

            }
            if (moc == 1)
            {
                naped="o";
            }
            if (moc == 2)
            {
                naped="O";
            }
            if (moc == 3)
            {
                naped="8";
            }





            switch(c)
            {
                case 119://w
                    y--;

                break;
                case 97://a
                    x--;

                break;
                case 115://s
                    moc++;

                break;
                case 100://d
                    x++;
                break;
                default: break;
            }
    }
    getch();
    endwin();
    return 0;

}


