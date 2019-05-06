#ifndef BIGO_HPP
#define BIGO_HPP

#include "Basher.hpp"

class BigO : public Basher {

public:
  BigO(void);
  BigO(int, int);
  BigO(Basher const &);
  ~BigO(void);
  BigO &operator=(BigO const &ob);

  virtual void update();
  int getHp(void) const;
  void getDamage(void);

private:
  double _accel;
  double _invis_time;
  int _hp;
};

#endif
