#include "../include/AObj.hpp"

int AObj::_xMax = 0;
int AObj::_yMax = 0;
AObj::AObj(void) : _x(0), _y(0) {}

AObj::AObj(int x, int y) : _x(x), _y(y), _w(1), _h(1) {}

AObj::AObj(int x, int y, int w, int h) : _x(x), _y(y), _w(w), _h(h) {}

AObj::AObj(AObj const &cp) { *this = cp; }

AObj::~AObj(void) {}

AObj &AObj::operator=(AObj const &ob) {
  _x = ob._x;
  _y = ob._y;
  _w = ob._w;
  _h = ob._h;
  return *this;
}

int AObj::getX(void) const { return _x; }
int AObj::getY(void) const { return _y; }
int AObj::getW(void) const { return _w; }
int AObj::getH(void) const { return _h; }
Sprite const &AObj::getSprite(void) const { return _s; }

void AObj::drawSprite(WINDOW *wnd) const { _s.drawSprite(wnd, _x, _y); }

void AObj::readSprite(std::string path) {
  _s = Sprite(path);
  _w = _s.getWidth();
  _h = _s.getHeight();
}

void AObj::move(int x, int y) {
  _x = x;
  if (_x < 0)
    _x = 0;
  if (_x >= (_xMax - _w))
    _x = _xMax - _w;
  _y = y;
  if (_y < 0)
    _y = 0;
  if (_y >= (_yMax - _h))
    _y = _yMax - _h;
}

void AObj::setMax(int x, int y) {
  _xMax = x;
  _yMax = y;
}

bool AObj::colidesWith(AObj *obj) {
  if (_x >= obj->_x + obj->_w || obj->_x >= _x + _w)
    return false;
  if (_y >= obj->_y + obj->_h || obj->_y >= _y + _h)
    return false;
  return true;
}
