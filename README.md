
# ncLife

This project is an implementation of [Conway's Game of Life][CGoL]
in C++ using [ncurses][ncurses]. 

This project is still in very early stages of development.
Currently all that happens when you run the program is that a randomly generated field of live/dead cells appears and pressing any button increments the generation by one.

See the **ToDo** for more details on what is planned.


# ToDo
 
 - Use `#pragma once`.
 - Add some constant starting state so I know the program does what I expect.
 - Should I use `std::vector<bool>` or a quadTree like [here][quadTree]?
 - Actually map out the backend, so that way the Game of Life and the Display to a terminal can be considered separately.
 - ...
 - Find out the standard way of implementing command line parameters.



  [CGoL]: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
  [ncurses]: https://en.wikipedia.org/wiki/Ncurses
  [quadTree]: http://www.drdobbs.com/jvm/an-algorithm-for-compressing-space-and-t/184406478


