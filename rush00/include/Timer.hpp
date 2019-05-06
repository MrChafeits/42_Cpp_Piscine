#ifndef TIMER_HPP
#define TIMER_HPP

#include <ctime>
#include <mach/mach_time.h>
#define ORWL_NANO (+1.0E-9)
#define ORWL_GIGA UINT64_C(1000000000)

class Timer {
private:
  uint64_t _startingTime;
  uint64_t _lastUpdate;
  double _orwl_timebase;
  double _deltaTime;
  double _frameTime;
  Timer();

  Timer &operator=(Timer &v);
  Timer(Timer &v);
  static Timer *_timer;

public:
  ~Timer();
  static Timer *instance();
  void updateTimer(); // call this every frame.
  double frameTime(); // of between frams;
  double runTime();
  void endFrame();    // call when frame ended.
  double deltaTime(); // call of main loop
};

#endif /* TIMER_HPP */
