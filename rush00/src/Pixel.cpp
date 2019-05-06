#include "../include/Pixel.hpp"

Pixel::Pixel() { _char = 0; }

Pixel::Pixel(unsigned flags) { _char = flags; }

Pixel::Pixel(Pixel const &f) { _char = f._char; }

Pixel::Pixel(std::string &token) { (void)token; }

Pixel::~Pixel(void) {}

Pixel &Pixel::operator=(Pixel const &f) {
  _char = f._char;
  return *this;
}

unsigned Pixel::getValue(void) const { return _char; }

void Pixel::setValue(unsigned c) { _char = c; }
