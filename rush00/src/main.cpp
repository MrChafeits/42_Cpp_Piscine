#include "../include/Game.hpp"
#include "../include/Vector.hpp"
#include <curses.h>
#include <iostream>
#include <string>

int main(void) {
  Game *g;
  g = Game::instance();
  g->initLoop();
  while (true) {
    g->getInput();
  }
  endwin();
  return 0;
}
