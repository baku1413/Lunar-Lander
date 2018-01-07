#include <cstdlib>
#include <iostream>
#include <string>
#include "main_gra.h"
#include "drawing.h"
#include <fstream>
#include <ncurses/ncurses.h>
/** \brief podprogram drukujacy zawartosc pliku txt
 * kiedy z menu przejdziemy do wyswietlenia wynikow program ma zczytac kazda linie z pliku HOF.txt i wyswietlic w konsoli
 * \param pobrana linia - pobrana linia z pliku
 * \param wynik - zmienna = pobranej lini, wypisywana w oknie konsoli
 * \return
 *
 */

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
