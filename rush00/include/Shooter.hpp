#ifndef SHOOTER_HPP
#define SHOOTER_HPP

#include "AEnemy.hpp"

class Shooter : public AEnemy {

public:
  Shooter(void);
  Shooter(int, int);
  Shooter(Shooter const &);
  ~Shooter(void);
  Shooter &operator=(Shooter const &ob);

  virtual void update();

private:
  double _moveCd;
  double _shootCd;
  double _localMoveTime;
  int _moveCount;
  static const int _shootTime;
  static const int _moveTile;
  static const double _minMoveTime;
  static const double _maxMoveTime;
};

#endif /* SHOOTER_HPP */
