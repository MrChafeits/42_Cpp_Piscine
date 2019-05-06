#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <string>

class Pixel {
private:
  unsigned _char;

public:
  Pixel();
  Pixel(unsigned flags);
  Pixel(std::string &token);
  Pixel(Pixel const &);

  ~Pixel();

  Pixel &operator=(Pixel const &);

  unsigned getValue() const;
  void setValue(unsigned);
};

#endif /* PIXEL_HPP */
