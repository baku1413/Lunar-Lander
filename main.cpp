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
int c;
int x=10; //start pos
int y=0;
int moc = 0;
string naped;
bool gra = true;

int main()
{


            if (moc > 3)
            {
                moc = 0;

            }
            initscr();
            clear();


            move(y,x);
            printw("A");
            move(y+1, x);
            printw("%d", naped);

            if (moc = 0)
            {
                string naped="o";

            }
            if (moc = 1)
            {
                string naped="o";
            }
            if (moc = 2)
            {
                string naped="O";
            }
            if (moc = 3)
            {
                string naped="0";
            }


            c=getch();



    while(c != 27) //ESC = exit
    {


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
                    moc++;
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
    main();
    endwin();
    return 0;




}


