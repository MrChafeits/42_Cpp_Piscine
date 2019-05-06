#ifndef GAME_HPP
#define GAME_HPP

#include "AEnemy.hpp"
#include "AObj.hpp"
#include "BigO.hpp"
#include "Bullet.hpp"
#include "Laser.hpp"
#include "Player.hpp"
#include "Timer.hpp"
#include "Vector.hpp"
#include <curses.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <thread>

#define MIN(a, b)                                                              \
  ((b) + (((a) - (b) & ((a) - (b)) >> (sizeof(int) * CHAR_BIT - 1))))
#define MAX(a, b)                                                              \
  ((a) - (((a) - (b) & ((a) - (b)) >> (sizeof(int) * CHAR_BIT - 1))))

#define PBUL_CLR (1)
#define EBUL_CLR (2)
#define ENEM_CLR (3)
#define PLYR_CLR (4)
#define ASTR_CLR (5)
#define NUMASTR (64)

class Game {

public:
  ~Game(void);
  Game &operator=(Game const &);

  void initLoop(void);
  void display(void);
  void getInput(void);

  static Game *instance();
  const Player &getPl1(void) const;
  Vector<Bullet *> &getBulletList(void);
  Vector<Laser *> &getLaserList(void);

private:
  static Game *_game;
  int _xMax, _yMax;
  WINDOW *_wnd;
  Player *_pl1;
  Timer *_tmr;
  Sprite _explosion;
  double _bigOspawn;
  static double _frameRate;
  double _frameCd;
  int _input;
  int _redraw;
  void _drawStarfield(void);
  void _endLoop(void);
  void _closeGame(void);
  void _playerShoot(int, int, int);
  void _enemyShoot(int, int);
  void _process(void);
  Vector<AEnemy *> _enemyList;
  Vector<BigO *> _BigOList;
  Vector<Bullet *> _bulletList;
  Vector<Laser *> _laserList;
  Game(void);
  Game(Game const &);
};

#endif /* GAME_HPP */
