#include "../include/Shooter.hpp"
#include "../include/Game.hpp"
#include "../include/Random.hpp"
#include "../include/Timer.hpp"
#include <cmath>

const double Shooter::_minMoveTime = 3;
const double Shooter::_maxMoveTime = 4;
const int Shooter::_shootTime = 5;
const int Shooter::_moveTile = 10;

Shooter::Shooter(void) {
  readSprite("resource/shooter.sprite");
  _moveCount = 0;
  _x = 0;
  _y = 0;
  _localMoveTime = Random::randomFloat(_minMoveTime, _maxMoveTime);
  _moveCd = _localMoveTime;
  _shootCd = _shootTime;
}

Shooter::Shooter(int x, int y) {
  readSprite("resource/shooter.sprite");
  _moveCount = 0;
  _x = x;
  _y = y;
  _localMoveTime = Random::randomFloat(_minMoveTime, _maxMoveTime);
  _moveCd = _localMoveTime;
  _shootCd = _shootTime;
}

Shooter::Shooter(Shooter const &f) { *this = f; }

Shooter::~Shooter(void) {}

Shooter &Shooter::operator=(Shooter const &ob) {
  _moveCd = ob._moveCd;
  _moveCount = ob._moveCount;
  _x = ob._x;
  _y = ob._y;
  _localMoveTime = ob._localMoveTime;
  return (*this);
}

void Shooter::update() {
  Timer *timer = Timer::instance();
  const Player &pl1 = Game::instance()->getPl1();
  _moveCd -= timer->frameTime();
  _shootCd -= timer->frameTime();
  if (_moveCd < 0)
    _moveCd = 0;
  if (_shootCd < 0)
    _shootCd = 0;
  if (_moveCd == 0) {
    _moveCd = _localMoveTime;
    _moveCount = _moveTile;
  }
  if (_moveCount != 0) {
    int dx = pl1.getX() - _x;
    int dy = pl1.getY() - _y;
    if (abs(dx) > abs(dy)) {
      if (dx < 0)
        move(_x - 1, _y);
      else
        move(_x + 1, _y);
    } else {
      if (dy < 0)
        move(_x, _y - 1);
      else
        move(_x, _y + 1);
    }
    _moveCount--;
  }
  if (_shootCd == 0) {
    Game::instance()->getBulletList().push_back(new Bullet(_x, _y));
    _shootCd = _shootTime;
  }
}
