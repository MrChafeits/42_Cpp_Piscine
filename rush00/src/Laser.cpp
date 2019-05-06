#include "Laser.hpp"
#include "Game.hpp"
#include "Timer.hpp"

Laser::Laser(void) {}

// failed laser.
Laser::Laser(int x, int y, int dir) {
  switch (dir) {
  case 1: // up
    _x = x;
    _y = -3 + y;
    _w = 1;
    _h = 3;
    break;
  case 2: // left
    _x = x - 3;
    _y = y;
    _w = 3;
    _h = 1;
    break;
  case 3: // down
    _x = x;
    _y = y;
    _w = 1;
    _h = 3;
    break;
  case 4: // right
    _x = x;
    _y = y;
    _w = 3;
    _h = 1;
    break;
  }
  _span = 0.10;
  _thickness = 1;
}

// thick laser.
Laser::Laser(int x, int y, int thickness, int dir, double span) {
  switch (dir) {
  case 1: // up
    _x = x - thickness / 2;
    _y = -1000 + y;
    _w = thickness;
    _h = 1000;
    break;
  case 2: // left
    _x = x - 1000;
    _y = y - thickness / 2;
    _w = 1000;
    _h = thickness;
    break;
  case 3: // down
    _x = x - thickness / 2;
    _y = y;
    _w = thickness;
    _h = 1000;
    break;
  case 4: // right
    _x = x;
    _y = y - thickness / 2;
    _w = 1000;
    _h = thickness;
    break;
  }
  _span = span;
  _thickness = thickness;
}

Laser::Laser(Laser const &f) { *this = f; }

Laser::~Laser(void) {}

Laser &Laser::operator=(Laser const &ob) {
  _x = ob._x;
  _y = ob._y;
  _w = ob._w;
  _h = ob._h;
  return (*this);
}

void Laser::update() {
  Timer *timer = Timer::instance();
  _span -= timer->frameTime();
}

double Laser::getSpan() { return _span; }

void Laser::display() {
  for (int i = 0; i < _h; i++) {
    for (int j = 0; j < _w; j++) {
      if (i + _y < 0 || i + _y >= _yMax || j + _x < 0 || j + _x >= _xMax)
        continue;
      if (_w == 3 || _h == 3)
        mvaddch(i + _y, j + _x,
                '$' | A_BOLD |
                    (rand() % 3 ? COLOR_PAIR(PBUL_CLR) : COLOR_PAIR(PLYR_CLR)));
      else {
        if (i == 0 || i == _h - 1 || j == 0 || j == _w - 1)
          mvaddch(
              i + _y, j + _x,
              ':' | A_BOLD |
                  (rand() % 3 ? COLOR_PAIR(PBUL_CLR) : COLOR_PAIR(PLYR_CLR)));
        else
          mvaddch(
              i + _y, j + _x,
              ((rand() % 95) + 32) | A_BOLD |
                  (rand() % 3 ? COLOR_PAIR(PBUL_CLR) : COLOR_PAIR(PLYR_CLR)));
      }
    }
  }
}
