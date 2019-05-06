#include "../include/Basher.hpp"
#include "../include/Game.hpp"
#include "../include/Random.hpp"
#include "../include/Timer.hpp"
#include <cmath>

const double Basher::_minAccel = 30;
const double Basher::_maxAccel = 50;
const double Basher::_maxSpeed = 20;

Basher::Basher(void) : _vx(0), _vy(0) {
  _px = _x;
  _py = _y;
  _accel = Random::randomFloat(_minAccel, _maxAccel);
  readSprite("resource/basher.sprite");
}

Basher::Basher(int x, int y) : _px(x), _py(y), _vx(0), _vy(0) {
  _accel = Random::randomFloat(_minAccel, _maxAccel);
  readSprite("resource/basher.sprite");
}

Basher::Basher(Basher const &f) { *this = f; }

Basher::~Basher(void) {}

Basher &Basher::operator=(Basher const &ob) {
  _px = ob._px;
  _py = ob._py;
  _vx = ob._vx;
  _vy = ob._vy;
  return (*this);
}

void Basher::update() {
  Timer *timer = Timer::instance();
  const Player &pl1 = Game::instance()->getPl1();
  double dx = pl1.getX() - _px;
  double dy = pl1.getY() - _py;
  double dLength = std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
  dx /= dLength;
  dy /= dLength;
  _vx += _accel * timer->frameTime() * dx;
  _vy += _accel * timer->frameTime() * dy;
  double vLength = std::sqrt(std::pow(_vx * 0.5, 2) + std::pow(_vy, 2));
  if (vLength > _maxSpeed) {
    _vx *= _maxSpeed / vLength;
    _vy *= _maxSpeed / vLength;
  }
  _px += _vx * timer->frameTime();
  _py += _vy * timer->frameTime();
  _x = std::round(_px);
  _y = std::round(_py);
}
