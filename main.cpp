#include <iostream>
using namespace std;
bool koniec;
const int wysokosc = 40;  //height
const int szerokosc = 80; //width
int x, y,  // wspolrzene statku

int main()
{
   setup();
   while (!koniec)
   {
       rys();
       wej();
       logi();
   }
   return 0;
}

void setup()
{
    koniec = false;   // gra jest w toku
    x = rand() % szerokosc;  //szeroko�� statku = losowa liczba z zakresu szeroko��=40
    y = wysokosc - 1;       // wysoko�� �eby zaczyna� z samej g�ry
}
void wej()
{

}
void rys()
{
    system("cls");//czy�ci terminal

    for (int i = 0; i < szerokosc; i++ )  //sciana mapy g�rna zbudowana z #
        cout << "#";
    cout << endl;

    for (int i = 0; i <wysokosc; i++)
        {
            for (int j = 0; j < wysokosc; j++)
            {
              if (j == 0)
                cout << "#";
                cout << " ";
              if  (j == szerokosc-1)
                cout << "#";
            }
        }

    for (int i = 0; i < szerokosc; i++ )  //sciana mapy g�rna zbudowana z #
        cout << "#";
    cout << endl;
}
void logi()
{

}

