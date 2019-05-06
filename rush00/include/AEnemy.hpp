#ifndef AENEMY_HPP
#define AENEMY_HPP

#include "AObj.hpp"

class AEnemy : public AObj {

public:
  AEnemy(void);
  AEnemy(AEnemy const &);
  virtual ~AEnemy(void);
  AEnemy &operator=(AEnemy const &ob);

private:
  //    int _health;
};

#endif /* AENEMY_HPP */
