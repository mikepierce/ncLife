/*
 * Mike Pierce (mapierce271@gmail.com)
 * ncLife
 * life.hpp
 */



#ifndef LIFE_HPP
#define LIFE_HPP
#include <queue>
#include <iostream>



class action /*lawsuit*/ {
    public:
        action(unsigned wye, unsigned exx, char cee)
            : y(wye), x(exx), c(cee) {};
        ~action() {};
        unsigned y;
        unsigned x;
        char c;
};



class Life {
    public:
        Life();
        Life(unsigned, unsigned);
        ~Life();
        void print();
        void update();
        void flush();
    private:
        unsigned rows, cols;
        std::queue<action*> actions;
        char** grid;
};



#endif

