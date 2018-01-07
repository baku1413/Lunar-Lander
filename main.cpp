#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include "main_gra.h"
#include "main.h"

/** \brief menu g³ówne gry
 * wybor kolejnych podprogramow za pomoca wpisywanej cyfry 1-4 lub q zeby wyjsc
 * \param program - zmienna boolean sprawdza czy menu glowne jest w toku
 * \param i - zmienna przechowujaca klawisz
 * \return
 *
 */

int main()
{
    bool program = true;
int i = 0;

    while (program) {

        std::cout << ".-." << std::endl;
        std::cout << ": :" << std::endl;
        std::cout << ": :   .-..-.,-.,-. .--.  .--. " << std::endl;
        std::cout << ": :__ : :; :: ,. :' .; ; : ..'" << std::endl;
        std::cout << ":___.'`.__.':_;:_;.__,_; :_;  " << std::endl;
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        std::cout << ".-.                   .-.           " << std::endl;
        std::cout << ": :                   : :           " << std::endl;
        std::cout << ": :    .--.  ,-.,-. .-' : .--. .--. " << std::endl;
        std::cout << ": :__ ' .; ; : ,. :' .; :' '_.': ..'" << std::endl;
        std::cout << ":___.'.__,_; :_;:_;`.__.'`.__.':_;  " << std::endl;
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;

        std::cout << "Bartosz Bak" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "STEROWANIE:" << std::endl;
        std::cout << "Klawisz W - zwiekszenie mocy silnikow" << std::endl;
        std::cout << "Klawisz S - zmiejszenie mocy silnikow" << std::endl;
        std::cout << "Klawisze A i D - sterowanie statkiem lewo prawo" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "Zadaniem gracza jest wyladowanie na planecie lub platformie" << std::endl;
        std::cout << "Pomyslne ladowanie jest wtedy gdy:" << std::endl;
        std::cout << "statek dotyka terenu z predkoscia mniejsza niz 5" << std::endl;
        std::cout << "Im mniejszy uzyskany wynik czyt. mniej zuzytego paliwa" << std::endl;
        std::cout << "Tym lepszy wynik gracza" << std::endl;
        std::cout << "Jesli ladowanie zostanie poprawnie na platformie" << std::endl;
        std::cout << "Wynik jest dzielony przez liczbe 100" << std::endl;
        std::cout << "" << std::endl;

        std::cout << "              :Wybierz tryb:            " << std::endl;
        std::cout << "[1] Gra" << std::endl;
        std::cout << "[2] Demo" << std::endl;
        std::cout << "[3] Tabela Wynikow" << std::endl;
        std::cout << "[4] Wyjscie" << std::endl;
        std::cout << ">";
        std::cin >> i;


        if (i == 1)
        {
          main_gra();

        }

        if (i== 2)
        {
            main_demo();

        }

        if (i==3)
        {
            main_wyniki();

        }

        if (i==4)
        {
            program = false;
        }
    }
}
