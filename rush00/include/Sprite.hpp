#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "Pixel.hpp"
#include <curses.h>
#include <fstream>
#include <sstream>
#include <string>

class Sprite {

private:
  int _width;
  int _height;
  Pixel **_grid;
  static int _xMax;
  static int _yMax;

public:
  Sprite(void);
  Sprite(std::string path);
  Sprite(Sprite const &);
  ~Sprite(void);
  Sprite &operator=(Sprite const &);
  void drawSprite(WINDOW *wnd, int x, int y) const;
  int getWidth() const;
  int getHeight() const;
  Pixel &getPixel(int x, int y) const;
  static void setMax(int xM, int yM);
};

#endif /* SPRITE_HPP */
