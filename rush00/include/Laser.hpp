#ifndef LASER_HPP
#define LASER_HPP

#include "AObj.hpp"
// acutally a missle.
class Laser : public AObj {

public:
  Laser();
  Laser(int x, int y, int dir);
  Laser(int x, int y, int thickness, int dir, double span);
  Laser(Laser const &);
  virtual ~Laser(void);
  Laser &operator=(Laser const &ob);

  virtual void update();
  void display();
  double getSpan();

private:
  double _span;
  int _thickness;
};

#endif /* LASER_HPP */
