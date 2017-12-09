#include "main_gra.h"
#include "drawing.h"
#include "cpp11_utils.h"
#include <cstdlib>

#include <iostream>
#include <ncurses/ncurses.h>
#include <string>


int main_demo() {


        int ground_level = 37;

        for (int i = 0; i < 80; i=i+1)
        {

            mvprintw(ground_level, i, "=");


        }

    return 0;


}
