#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <cstdlib>
#include <mach/mach_time.h>

class Random {
private:
  Random();
  Random(Random &);
  Random &operator=(Random const &);
  ~Random();

public:
  static void initRandom();
  static float random();
  static int randomInt(int a, int b);
  static float randomFloat(float a, float b);
};

#endif /* RANDOM_HPP */
