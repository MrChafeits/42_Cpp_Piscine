#ifndef BULLET_HPP
#define BULLET_HPP

#include "AObj.hpp"

// acutally a missle.
class Bullet : public AObj {

public:
  Bullet(int x, int y);
  Bullet(Bullet const &);
  virtual ~Bullet(void);
  Bullet &operator=(Bullet const &ob);

  virtual void update();
  double getSpan();

private:
  Bullet();
  double _span;
  static const double _accel;
  double _px;
  double _py;
  double _vx;
  double _vy;
};

#endif /* BULLET_HPP */
