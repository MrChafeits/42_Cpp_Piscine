#ifndef AOBJ_HPP
#define AOBJ_HPP

#include "Sprite.hpp"
#include <curses.h>
#include <string>

class AObj {

public:
  AObj(void);
  AObj(int x, int y);
  AObj(int x, int y, int w, int h);
  AObj(AObj const &);
  ~AObj(void);
  AObj &operator=(AObj const &ob);

  int getX(void) const;
  int getY(void) const;
  int getW(void) const;
  int getH(void) const;
  Sprite const &getSprite(void) const;
  void readSprite(std::string path);
  void drawSprite(WINDOW *) const;
  void move(int x, int y);
  static void setMax(int x, int y);
  virtual void update(void) = 0;
  bool colidesWith(AObj *);

protected:
  int _x;
  int _y;
  int _w;
  int _h;
  static int _xMax;
  static int _yMax;
  Sprite _s;

private:
};

#endif /* AOBJ_HPP */
