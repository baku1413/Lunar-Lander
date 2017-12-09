#include <cstdlib>
#include <iostream>
#include <string>
#include "main_gra.h"
#include "drawing.h"
#include <fstream>
#include <ncurses/ncurses.h>
using namespace std;
int main_wyniki() {
    system("cls");
    fstream wyniki;
    wyniki.open("HOF.txt" , ios::in);
    if (wyniki.good()==false)
    {
        clear();
        cout<<"PROBLEM Z PLIKIEM";
        exit(0);
    }
    string pobrana_linia;
    string wynik;
    while(getline(wyniki, pobrana_linia))
    {

    wynik=pobrana_linia;
    cout<<wynik<<endl;

    }

return 0;

}
