#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "AObj.hpp"
#include "Timer.hpp"
#include <string>

class Player : public AObj {

public:
  Player(void);
  Player(int, int);
  Player(int, int, int, int);
  Player(std::string const &);
  Player(Player const &);
  ~Player(void);
  Player &operator=(Player const &);

  virtual void update();
  void moveUp();
  void moveLeft();
  void moveRight();
  void moveDown();
  void shootUp(int x, int y);
  void shootDown(int x, int y);
  void shootLeft(int x, int y);
  void shootRight(int x, int y);
  void spendCharge(int *thick, double *span);
  void die(int x, int y);
  void changeFireMode(void);
  void getDamage(int x, int y);
  int getHp(void) const;

private:
  std::string _name;
  double _v_speed; // per second.
  double _h_speed; // per seocnd.
  double _move_cd;
  double _invis_time;
  int _hp;
  int _fmode;
  double _charge_time;
};

#endif /* PLAYER_HPP */
