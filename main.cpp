/*
 * Mike Pierce (mapierce271@gmail.com)
 * ncLife
 * main.cpp
 *
 * http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/
 * https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
 *
 */



#include <ncurses.h>
#include <iostream>
#include "life.hpp"



int main() {
//int main(int argc, char** argv) {

    initscr();
    clear();
    cbreak();
    noecho();
    nonl();
    keypad(stdscr, TRUE);
    // turn the cursor off

    unsigned rows, cols;
    getmaxyx(stdscr, rows, cols);
    Life conway(rows, cols);
    conway.flush();
    //conway.print();
    getchar();
    
    while(true) {
        conway.update();
        conway.flush();
        // conway.print();
        getchar();
    }

    endwin();
    return 0;
}



