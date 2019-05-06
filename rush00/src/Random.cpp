#include "Random.hpp"

void Random::initRandom() { srand(mach_absolute_time()); }

float Random::random() { return rand() / (float)RAND_MAX; }

int Random::randomInt(int a, int b) { return rand() % (b - a) + a; }

float Random::randomFloat(float a, float b) {
  return (rand() / (float)RAND_MAX) * (b - a) + a;
}
