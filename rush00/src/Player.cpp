#include "../include/Player.hpp"
#include "../include/Game.hpp"
#include "../include/Laser.hpp"
#include <iostream>
#include <unistd.h>
Player::Player(void)
    : AObj(10, 10, 1, 1), _v_speed(40), _h_speed(80), _move_cd(0),
      _invis_time(0), _hp(8), _charge_time(0) {
  _name = "John Schuut";
}

Player::Player(std::string const &n)
    : _name(n), _v_speed(40), _h_speed(40), _move_cd(0), _invis_time(0), _hp(8),
      _charge_time(0) {}

Player::Player(Player const &cp) { *this = cp; }

Player::~Player(void) {}

Player &Player::operator=(Player const &ob) {
  this->_name = ob._name;
  this->_v_speed = ob._v_speed;
  this->_h_speed = ob._h_speed;
  this->_move_cd = ob._move_cd;
  this->_invis_time = ob._invis_time;
  this->_hp = ob._hp;
  this->_fmode = ob._fmode;
  this->_charge_time = ob._charge_time;
  return *this;
}

void Player::update() {
  Timer *timer = Timer::instance();
  _move_cd -= timer->frameTime();
  if (_move_cd < 0)
    _move_cd = 0;
  _invis_time -= timer->frameTime();
  if (_invis_time < 0)
    _move_cd = 0;
  _charge_time += timer->frameTime();
}

void Player::moveUp() {
  if (_move_cd > 0)
    return;
  move(_x, _y - 1);
  _move_cd = 1 / _v_speed;
}

void Player::moveLeft() {
  if (_move_cd > 0)
    return;
  move(_x - 1, _y);
  _move_cd = 1 / _h_speed;
}

void Player::moveRight() {
  if (_move_cd > 0)
    return;
  move(_x + 1, _y);
  _move_cd = 1 / _h_speed;
}

void Player::moveDown() {
  if (_move_cd > 0)
    return;
  move(_x, _y + 1);
  _move_cd = 1 / _v_speed;
}

void Player::shootUp(int x, int y) {
  int o = (x + (_w / 2));
  Game *game = Game::instance();
  if (_fmode && _charge_time < 1.5)
    game->getLaserList().push_back(new Laser(o, y, 1));
  else {
    int thickness;
    double span;
    spendCharge(&thickness, &span);
    game->getLaserList().push_back(new Laser(o, y, thickness, 1, span));
  }
  _charge_time = 0;
}

void Player::shootDown(int x, int y) {
  int o = (x + (_w / 2));
  Game *game = Game::instance();
  if (_fmode && _charge_time < 1.5)
    game->getLaserList().push_back(new Laser(o, y + _h, 3));
  else {
    int thickness;
    double span;
    spendCharge(&thickness, &span);
    game->getLaserList().push_back(new Laser(o, y + _h, thickness, 3, span));
  }
  _charge_time = 0;
}

void Player::shootRight(int x, int y) {
  int o = (y + (_h / 2));
  Game *game = Game::instance();
  if (_fmode && _charge_time < 1.5)
    game->getLaserList().push_back(new Laser(x + _w, o, 4));
  else {
    int thickness;
    double span;
    spendCharge(&thickness, &span);
    game->getLaserList().push_back(new Laser(x + _w, o, thickness, 4, span));
  }
  _charge_time = 0;
}

void Player::shootLeft(int x, int y) {
  int o = (y + (_h / 2));
  Game *game = Game::instance();
  if (_fmode && _charge_time < 1.5)
    game->getLaserList().push_back(new Laser(x, o, 2));
  else {
    int thickness;
    double span;
    spendCharge(&thickness, &span);
    game->getLaserList().push_back(new Laser(x, o, thickness, 2, span));
  }
  _charge_time = 0;
}

void Player::changeFireMode(void) {
  _fmode = !_fmode;
  _charge_time = 0;
}

void Player::die(int x, int y) {
  int i = ((y - 1) / 2) - 3;
  int j = ((x - 1) / 2) - 28;
  mvprintw(i + 0, j,
           " _____   ___  ___  ___ _____   _____  _   _ ___________ ");
  mvprintw(i + 1, j,
           "|  __ \\ / _ \\ |  \\/  ||  ___| |  _  || | | |  ___| ___ \\");
  mvprintw(i + 2, j,
           "| |  \\// /_\\ \\| .  . || |__   | | | || | | | |__ | |_/ /");
  mvprintw(i + 3, j,
           "| | __ |  _  || |\\/| ||  __|  | | | || | | |  __||    / ");
  mvprintw(i + 4, j,
           "| |_\\ \\| | | || |  | || |___  \\ \\_/ /\\ \\_/ / |___| |\\ \\ ");
  mvprintw(i + 5, j,
           " \\____/\\_| |_/\\_|  |_/\\____/   \\___/  \\___/\\____/\\_| \\_|");
  refresh();
  sleep(4);
  while (getch() == ERR)
    ;
  sleep(1);
  endwin();
  exit(0);
}

int Player::getHp(void) const { return _hp; }

void Player::getDamage(int x, int y) {
  if (_invis_time > 0)
    return;
  _hp--;
  if (_hp <= 0)
    die(x, y);
  _invis_time = 4;
}

void Player::spendCharge(int *thick, double *span) {
  if (!_fmode) {
    *thick = 1;
    *span = 0.5;
  } else {
    if (_charge_time < 2) {
      *thick = 1;
      *span = 0.5;
    } else if (_charge_time < 2.5) {
      *thick = 3;
      *span = 0.75;
    } else if (_charge_time < 3) {
      *thick = 5;
      *span = 1;
    } else if (_charge_time < 3.5) {
      *thick = 7;
      *span = 1.5;
    } else if (_charge_time < 5) {
      *thick = 9;
      *span = 1.75;
    } else {
      *thick = 11;
      *span = 2;
    }
  }
}
