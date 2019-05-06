#ifndef BASHER_HPP
#define BASHER_HPP

#include "AEnemy.hpp"

class Basher : public AEnemy {

public:
  Basher(void);
  Basher(int, int);
  Basher(Basher const &);
  ~Basher(void);
  Basher &operator=(Basher const &ob);

  virtual void update();

protected:
  double _px;
  double _py;
  double _vx;
  double _vy;
  double _accel;
  static const double _minAccel;
  static const double _maxAccel;
  static const double _maxSpeed;
};

#endif /* BASHER_HPP */
