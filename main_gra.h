#ifndef __MAIN_GRA_H
#define __MAIN_GRA_H


/*! \brief g³owna funckja gry
 *  funkcja ta odpowiada za wyswietlanie wyniku wykrywanie kolizji z podlozem rysowanie platformy odczyt wcisnietych klawiszy itp
 *  to glowny czlon programu
 *
 * \param ship_thrust - aktualna moc napedu
 * \param ship_position_y - pozycja y statku = parametrowi y
 * \param ship_velocity - predkosc statku
 * \param gravity - wartosc grawitacji znak na sek^2
 * \param time_delta - sta³a czasowa ustajalaca "framerate" jak szybko dziala program
 * \param start - czas pobierany z funkcji TimeMs()
 * \param ground_level - poziom podloza do ladowania
 * \param platformax - polozenie platformy x
 * \param platformay- polozenie platformy y
 * \param graa - zmienna boolean true jesli gra sie toczy
 * \param c - zmienna przechowujaca wcisniety klawisz
 * \param now - czas
 * \param delta - czas jaki uplynal od teraz czyli czas zmierzony wczesniej-czas teraz
 * \param y - pozycja statku y
 * \param x - poyzcja statku x
 * \param score - wynik gracza
 * \param pomyslnosc - zmienna string ma za zadanie przechowac pomyslonsc wykoannego zadania i byc wpisana do wyniku koncowego
 *
 *\return
 *
 */

// deklaracja funkcji
int main();
int main_gra();
int main_demo();
int main_wyniki();

#endif // __MAIN_GRA_H

