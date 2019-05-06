#include "BigO.hpp"
#include "../include/Game.hpp"
#include "../include/Random.hpp"
#include "../include/Timer.hpp"
#include <cmath>

BigO::BigO(void) {
  _px = _x;
  _py = _y;
  _vx = 0;
  _vy = 0;
  _accel = 20;
  readSprite("resource/bigO.sprite");
  _invis_time = 0;
  _hp = 8;
}

BigO::BigO(int x, int y) {
  _x = x;
  _y = y;
  _px = x;
  _py = y;
  _vx = 0;
  _vy = 0;
  _accel = 20;
  readSprite("resource/bigO.sprite");
  _invis_time = 0;
  _hp = 8;
}

BigO::BigO(Basher const &f) { *this = f; }

BigO::~BigO(void) {}

BigO &BigO::operator=(BigO const &ob) {
  _px = ob._px;
  _py = ob._py;
  _vx = ob._vx;
  _vy = ob._vy;
  return (*this);
}

void BigO::update() {
  Timer *timer = Timer::instance();
  _invis_time -= timer->frameTime();
  const Player &pl1 = Game::instance()->getPl1();
  double dx = pl1.getX() - _px;
  double dy = pl1.getY() - _py;
  double dLength = std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
  dx /= dLength;
  dy /= dLength;
  _vx += _accel * timer->frameTime() * dx;
  _vy += _accel * timer->frameTime() * dy;
  double vLength = std::sqrt(std::pow(_vx * 0.5, 2) + std::pow(_vy, 2));
  if (vLength > 50) {
    _vx *= _maxSpeed / vLength;
    _vy *= _maxSpeed / vLength;
  }
  _px += _vx * timer->frameTime();
  _py += _vy * timer->frameTime();
  _x = std::round(_px);
  _y = std::round(_py);
}

void BigO::getDamage() {
  if (_invis_time > 0)
    return;
  _hp--;
  _invis_time = 3;
}

int BigO::getHp(void) const { return (_hp); }
