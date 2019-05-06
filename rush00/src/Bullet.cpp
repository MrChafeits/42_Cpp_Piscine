#include "Bullet.hpp"
#include "Game.hpp"
#include "Timer.hpp"
#include <cmath>

const double Bullet::_accel = 20;

Bullet::Bullet(void) {}

Bullet::Bullet(int x, int y) {
  _span = 1.5;
  _px = x;
  _py = y;
  _x = x;
  _y = y;
  _vx = 0;
  _vy = 0;
  readSprite("resource/bullet.sprite");
}

Bullet::Bullet(Bullet const &f) {
  *this = f;
  readSprite("resource/bullet.sprite");
}

Bullet::~Bullet(void) {}

Bullet &Bullet::operator=(Bullet const &ob) {
  _span = 3;
  _px = ob._px;
  _py = ob._py;
  _x = ob._x;
  _x = ob._x;
  _vx = ob._vx;
  _vy = ob._vy;
  return (*this);
}

void Bullet::update() {
  Timer *timer = Timer::instance();
  const Player &pl1 = Game::instance()->getPl1();
  _span -= timer->frameTime();
  double dx = pl1.getX() - _px;
  double dy = pl1.getY() - _py;
  double dLength = std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
  dx /= dLength;
  dy /= dLength;
  _vx += _accel * timer->frameTime() * dx;
  _vy += _accel * timer->frameTime() * dy;
  _px += _vx * timer->frameTime();
  _py += _vy * timer->frameTime();
  _x = std::round(_px);
  _y = std::round(_py);
}

double Bullet::getSpan() { return _span; }
