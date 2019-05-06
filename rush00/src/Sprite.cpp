#include "../include/Sprite.hpp"
#include "../include/Game.hpp"
#include <curses.h>

int Sprite::_xMax = 0;
int Sprite::_yMax = 0;

Sprite::Sprite(void) : _width(1), _height(1) {
  _grid = new Pixel *[_height];
  *_grid = new Pixel[_width];
  _grid[0][0].setValue('@' | COLOR_PAIR(PLYR_CLR));
}

Sprite::Sprite(std::string path) {
  std::stringstream s;
  std::ifstream ifs;

  ifs.open(path, std::ifstream::in);
  if (ifs.good())
    s << ifs.rdbuf();
  else
    std::exit(-1);
  ifs.close();
  s >> _width >> _height;
  _grid = new Pixel *[_height];
  for (int i = 0; i < _height; i++) {
    _grid[i] = new Pixel[_width];
    for (int j = 0; j < _width; j++) {
      char val;
      s >> val;
      std::cerr << val;
      _grid[i][j].setValue(val);
    }
  }
}

Sprite::Sprite(Sprite const &f) { *this = f; }

Sprite::~Sprite(void) {
  for (int i = 0; i < _height; i++) {
    delete[] _grid[i];
  }
  delete[] _grid;
}

Sprite &Sprite::operator=(Sprite const &f) {
  for (int i = 0; i < _height; i++) {
    delete[] _grid[i];
  }
  delete[] _grid;
  _width = f._width;
  _height = f._height;
  _grid = new Pixel *[f._height];
  for (int i = 0; i < _height; i++) {
    _grid[i] = new Pixel[f._width];
    for (int j = 0; j < _width; j++) {
      _grid[i][j] = f._grid[i][j];
    }
  }
  return *this;
}

void Sprite::drawSprite(WINDOW *wnd, int x, int y) const {
  for (int i = 0; i < _height; i++) {
    for (int j = 0; j < _width; j++) {
      if (i + y < 0 || i + y >= _yMax || j + x < 0 || j + x >= _xMax ||
          _grid[i][j].getValue() == 0)
        continue;
      mvwprintw(wnd, y + i, x + j, "%c", _grid[i][j].getValue());
    }
  }
}

int Sprite::getWidth() const { return _width; }

int Sprite::getHeight() const { return _height; }

Pixel &Sprite::getPixel(int x, int y) const { return _grid[y][x]; }

void Sprite::setMax(int xM, int yM) {
  _xMax = xM;
  _yMax = yM;
}
