/*
 * Mike Pierce (mapierce271@gmail.com)
 * ncLife
 * life.cpp
 */



#include <cstdlib>
#include <ncurses.h>
#include "life.hpp"



Life::Life() {}

Life::Life(unsigned r, unsigned c) : rows(r+2), cols(c+2) {
    grid = new char*[rows];
    for(unsigned i = 0; i < rows; ++i) {
        grid[i] = new char[cols];
        for(unsigned j = 0; j < cols; ++j) {
            action* tmp = new action(i, j, rand()%7?' ':'0');
            actions.push(tmp);
        }
    }
    // Zero out the borders of the grid...
    for(unsigned i = 0; i < rows; ++i) {
        action* tmp = new action(i, 0, ' ');
        actions.push(tmp);
        tmp = new action(i, cols-1, ' ');
        actions.push(tmp);
        //grid[i][0] = grid[i][cols-1] = grid[i][1] = grid[i][cols-2] = ' ';
    }
    for(unsigned j = 0; j < cols; ++j) {
        action* tmp = new action(0, j, ' ');
        actions.push(tmp);
        tmp = new action(rows-1, j, ' ');
        actions.push(tmp);
        //grid[0][j] = grid[rows-1][j] = grid[1][j] = grid[rows-2][j] = ' ';
    }
}

Life::~Life() {
    for(unsigned i = 0; i < rows; ++i)
        delete grid[i];
    delete grid;
}

// UPDATE THIS ONE!!!
void Life::print() {
    move(0,0);
    for(unsigned i = 0; i < rows; ++i) {
        for(unsigned j = 0; j < cols; ++j) {
            addch(grid[i][j]);
            move(i,j);
        }
        move(i,0);
    }
    refresh();
}

void Life::update() {
    unsigned sum = 0;
    for(unsigned i = 1; i < rows-1; ++i) {
        for(unsigned j = 1; j < cols-1; ++j) {
            sum = (grid[i-1][j]=='0'?1:0)+
                  (grid[i+1][j]=='0'?1:0)+
                  (grid[i][j-1]=='0'?1:0)+
                  (grid[i][j+1]=='0'?1:0)+
                  (grid[i-1][j-1]=='0'?1:0)+
                  (grid[i-1][j+1]=='0'?1:0)+
                  (grid[i+1][j-1]=='0'?1:0)+
                  (grid[i+1][j+1]=='0'?1:0);
            if(grid[i][j]=='0' && sum != 2 && sum != 3) {
                action* tmp = new action(i, j, ' ');
                actions.push(tmp);
            }
            else if(grid[i][j]==' ' && sum == 3) {
                action* tmp = new action(i, j, '0');
                actions.push(tmp);
            }
            sum = 0;
        }
    }
}

void Life::flush() {
    while(!actions.empty()) {
        action* tmp = actions.front();
        grid[tmp->y][tmp->x] = tmp->c;
        move(tmp->y-1, tmp->x-1);
        addch(tmp->c);
        actions.pop();
        delete tmp;
    }
    refresh();
}




