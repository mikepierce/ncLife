/*
 * Mike Pierce (mapierce271@gmail.com)
 * ncLife
 * main.cpp
 *
 * http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/
 * https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
 *
 */

// STD::VECTOR<bool> IS SMART AND SPACE EFFICIENT AND SHOULD BE USED.
// http://stackoverflow.com/questions/14433626/variable-size-bitset


#include <ncurses.h>
#include <iostream>
#include "life.hpp"



int main() {
//int main(int argc, char** argv) {

    const int a = 34;
    std::bitset<a> taco;
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
    getchar();
    
    while(true) {
        conway.update();
        conway.flush();
        getchar();
    }

    endwin();
    return 0;
}



