#include "../include/Game.hpp"
#include "../include/Basher.hpp"
#include "../include/BigO.hpp"
#include "../include/Random.hpp"
#include "../include/Shooter.hpp"
#include <string>

static unsigned score;

Game *Game::_game = nullptr;

double Game::_frameRate = 60;

Game::Game(void) {}

Game::~Game(void) { endwin(); }

Game *Game::instance() {
  if (_game == nullptr)
    _game = new Game();
  return _game;
}

Game &Game::operator=(Game const &ob) {
  this->_game = ob._game;
  this->_xMax = ob._xMax;
  this->_yMax = ob._yMax;
  this->_wnd = ob._wnd;
  this->_pl1 = ob._pl1;
  this->_tmr = ob._tmr;
  this->_explosion = ob._explosion;
  this->_frameRate = ob._frameRate;
  this->_input = ob._input;
  this->_redraw = ob._redraw;
  // this->_enemyList = ob._enemyList;
  // this->_bulletList = ob._bulletList;
  // this->_laserList = ob._laserList;
  return *this;
}

void Game::_drawStarfield(void) {
  register int i;
  static int coords[NUMASTR * 2];
  if (_redraw == -1) { // INIT
    for (i = 0; i < NUMASTR; i++) {
      coords[i * 2] = (rand() % (_yMax - 1));
      coords[(i * 2) + 1] = (rand() % (_xMax - 1));
    }
    _redraw = 4;
  } else if (_redraw == 0) { // UP
    for (i = 0; i < NUMASTR; i++) {
      if (coords[i * 2] - 2 < 0)
        coords[i * 2] = (_yMax - 1);
      else
        coords[i * 2] = (coords[i * 2] - 2) % (_yMax - 1);
    }
    _redraw = 4;
  } else if (_redraw == 1) { // LEFT
    for (i = 0; i < NUMASTR; i++) {
      if (coords[(i * 2) + 1] - 2 < 0)
        coords[(i * 2) + 1] = (_xMax - 1);
      else
        coords[(i * 2) + 1] = (coords[(i * 2) + 1] - 2) % (_xMax - 1);
    }
    _redraw = 4;
  } else if (_redraw == 2) { // DOWN
    for (i = 0; i < NUMASTR; i++) {
      coords[i * 2] = (coords[i * 2] + 2) % (_yMax - 1);
    }
    _redraw = 4;
  } else if (_redraw == 3) { // RIGHT
    for (i = 0; i < NUMASTR; i++) {
      coords[(i * 2) + 1] = (coords[(i * 2) + 1] + 2) % (_xMax - 1);
    }
    _redraw = 4;
  } else {
    _redraw = 4;
  }
  for (i = 0; i < NUMASTR; i++)
    mvwaddch(_wnd, coords[i * 2], coords[(i * 2) + 1],
             '*' | COLOR_PAIR(ASTR_CLR));
}

void Game::initLoop(void) {
  srand(time(0));
  initscr();
  cbreak();
  noecho();
  curs_set(0);
  getmaxyx(stdscr, _yMax, _xMax);
  keypad(stdscr, TRUE);
  _explosion = Sprite("resource/explosion.sprite");
  _frameCd = 0;
  _redraw = -1;
  Random::initRandom();
  _tmr = Timer::instance();
  _wnd = newwin(_yMax, _xMax, 0, 0);
  nodelay(stdscr, TRUE);
  AObj::setMax(_xMax, _yMax);
  Sprite::setMax(_xMax, _yMax);
  _pl1 = new Player();
  _pl1->readSprite("resource/player.sprite");
  _pl1->move(_xMax / 2 - _pl1->getW(), _yMax / 2 - _pl1->getH());
  start_color();
  init_pair(PBUL_CLR, COLOR_BLUE, COLOR_BLACK);
  init_pair(EBUL_CLR, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(ENEM_CLR, COLOR_RED, COLOR_BLACK);
  init_pair(PLYR_CLR, COLOR_CYAN, COLOR_BLACK);
  init_pair(ASTR_CLR, COLOR_YELLOW, COLOR_BLACK);
  _bigOspawn = 0;
}

const Player &Game::getPl1(void) const { return *_pl1; }

Vector<Bullet *> &Game::getBulletList(void) { return _bulletList; }

Vector<Laser *> &Game::getLaserList(void) { return _laserList; }

#define objCW(e) ((e)->getW() / 2)
#define objCH(e) ((e)->getH() / 2)
#define objCX(e) ((e)->getX() + (objCW((e))))
#define objCY(e) ((e)->getY() + (objCH((e))))
#define objHitX(e, x)                                                          \
  (objCX((e)) - objCW((e)) <= (x) && objCX((e)) + objCW((e)) >= (x))
#define objHitY(e, x)                                                          \
  (objCY((e)) - objCH((e)) <= (x) && objCY((e)) + objCH((e)) >= (x))

void Game::getInput(void) {
  register int i, x, y;
  int ch;

  ch = getch();
  if (ch != ERR)
    _input = ch;
  _tmr->updateTimer();
  if (_tmr->frameTime() < 1 / _frameRate)
    return;
  wclear(_wnd);
  _pl1->update();
  // make better way of making enemy.
  if (_enemyList.size() < 64 &&
      fmod(_tmr->runTime(), 4.0) < (log2(_tmr->runTime() / 2) * 0.0125) &&
      _tmr->runTime() > 1) {
    if (rand() % 100 < 75)
      _enemyList.push_back(new Basher(rand() % _xMax, rand() % _yMax));
    else {
      if (_tmr->runTime() - _bigOspawn > 30) {
        _BigOList.push_back(new BigO(rand() % _xMax, rand() % _yMax));
        _bigOspawn = _tmr->runTime();
      } else
        _enemyList.push_back(new Shooter(rand() % _xMax, rand() % _yMax));
    }
  }
  for (i = _enemyList.size() - 1; i >= 0; i--) {
    _enemyList[i]->update();
  }
  for (i = _BigOList.size() - 1; i >= 0; i--) {
    _BigOList[i]->update();
  }
  for (i = _bulletList.size() - 1; i >= 0; i--) {
    if (_bulletList[i]->getSpan() < 0) {
      wattron(_wnd, COLOR_PAIR(EBUL_CLR));
      _explosion.drawSprite(_wnd, _bulletList[i]->getX() - 1,
                            _bulletList[i]->getY() - 1);
      wattroff(_wnd, COLOR_PAIR(EBUL_CLR));
      _bulletList.erase(i);
    } else
      _bulletList[i]->update();
  }
  for (i = _laserList.size() - 1; i >= 0; i--) {
    if (_laserList[i]->getSpan() < 0)
      _laserList.erase(i);
    else
      _laserList[i]->update();
  }
  x = _pl1->getX();
  y = _pl1->getY();
  Laser laser;
  switch (_input) {
  case 'w':
    _pl1->moveUp();
    _redraw = 0;
    break;
  case 'a':
    _pl1->moveLeft();
    _redraw = 1;
    break;
  case 's':
    _pl1->moveDown();
    _redraw = 2;
    break;
  case 'd':
    _pl1->moveRight();
    _redraw = 3;
    break;
  case KEY_UP:
    _pl1->shootUp(x, y);
    break;
  case KEY_LEFT:
    _pl1->shootLeft(x, y);
    break;
  case KEY_DOWN:
    _pl1->shootDown(x, y);
    break;
  case KEY_RIGHT:
    _pl1->shootRight(x, y);
    break;
  case ' ':
    _pl1->changeFireMode();
    break;
  case ERR:
  default:
    break;
  }
  _drawStarfield();
  wattron(_wnd, COLOR_PAIR(PLYR_CLR));
  _pl1->drawSprite(_wnd);
  wattroff(_wnd, COLOR_PAIR(PLYR_CLR));

  for (i = _laserList.size() - 1; i >= 0; i--) {
    for (int j = _enemyList.size() - 1; j >= 0; j--) {
      if (_laserList[i]->colidesWith(_enemyList[j])) {
        score += 100;
        _enemyList.erase(j);
      }
    }
    for (int j = _BigOList.size() - 1; j >= 0; j--) {
      if (_laserList[i]->colidesWith(_BigOList[j])) {
        _BigOList[j]->getDamage();
        if (_BigOList[j]->getHp() <= 0) {
          score += 1000;
          _BigOList.erase(j);
        }
      }
    }
    _laserList[i]->display();
  }
  // draw and update screen

  wattron(_wnd, COLOR_PAIR(EBUL_CLR));
  for (i = _bulletList.size() - 1; i >= 0; i--) {
    if (_pl1->colidesWith(_bulletList[i]))
      _pl1->getDamage(_xMax, _yMax);
    _bulletList[i]->drawSprite(_wnd);
  }
  wattroff(_wnd, COLOR_PAIR(EBUL_CLR));

  wattron(_wnd, COLOR_PAIR(ENEM_CLR));
  for (i = _enemyList.size() - 1; i >= 0; i--) {
    if (_pl1->colidesWith(_enemyList[i]))
      _pl1->getDamage(_xMax, _yMax);
    _enemyList[i]->drawSprite(_wnd);
  }
  for (i = _BigOList.size() - 1; i >= 0; i--) {
    if (_pl1->colidesWith(_BigOList[i]))
      _pl1->getDamage(_xMax, _yMax);
    _BigOList[i]->drawSprite(_wnd);
  }
  wattroff(_wnd, COLOR_PAIR(ENEM_CLR));

  mvwprintw(_wnd, _yMax - 2, 0, "Score: %010d", score);
  mvwprintw(_wnd, _yMax - 3, 0, "Lives: ");
  wattron(_wnd, COLOR_PAIR(PLYR_CLR));
  for (i = _pl1->getHp(); i > 0; i--)
    mvwaddch(_wnd, _yMax - 3, 6 + i, '@');
  wattroff(_wnd, COLOR_PAIR(PLYR_CLR));
  mvwprintw(_wnd, _yMax - 1, 0, "Time: %11.2f", _tmr->runTime());
  wrefresh(_wnd);
  _input = ERR;
  _tmr->endFrame();
}
#undef objCW
#undef objCH
#undef objCX
#undef objCY
#undef objHitX
#undef objHitY
