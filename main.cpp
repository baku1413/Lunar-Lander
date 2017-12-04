#include <cstdlib>
#include <iostream>
#include <stdlib.h>

int main()
{
int i = 0;


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


    std::cout << "              :Wybierz tryb:            " << std::endl;
    std::cout << "[1] Gra" << std::endl;
    std::cout << "[2] Demo" << std::endl;
    std::cout << "[3] Tabela Wynikow" << std::endl;
    std::cout << "[4] Wyjscie" << std::endl;
    std::cout << ">";
    std::cin >> i;


    if (i == 1)
    {
      //main_gra();
      std::cout << "Lmaoo" << std::endl;
    }

    if (i== 2)
    {
        //main_demo();
        std::cout << "demoo" << std::endl;
    }

    if (i==3)
    {
        //main_wyniki();
        std::cout << "XDDD" << std::endl;
    }

    if (i==4)
    {
        exit(0);
    }

}

    /*
    switch (i)
    {
    case 1:
        std::cout << "Lmaoo" << std::endl;
        //main_gra();
    case 2:
        std::cout << "demoo" << std::endl;
        //main_demo();
    case 3:
        //main_wyniki();
        std::cout << "XDDD" << std::endl;
    case 4:
        break;
    }



    return 0;
}

*/
