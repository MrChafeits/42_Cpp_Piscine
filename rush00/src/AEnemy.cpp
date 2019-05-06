#include "../include/AEnemy.hpp"

AEnemy::AEnemy(void) {}

AEnemy::AEnemy(AEnemy const &f) : AObj(f) {}

AEnemy::~AEnemy(void) {}

AEnemy &AEnemy::operator=(AEnemy const &ob) {
  (void)ob;
  return (*this);
}
