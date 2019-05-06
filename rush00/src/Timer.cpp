#include "../include/Timer.hpp"

Timer *Timer::_timer = NULL;

Timer::Timer() {
  mach_timebase_info_data_t tb;
  mach_timebase_info(&tb);
  _orwl_timebase = tb.numer;
  _orwl_timebase /= tb.denom;
  _startingTime = mach_absolute_time();
  _deltaTime = 0;
  _frameTime = 0;
  _lastUpdate = _startingTime;
  _timer = this;
}

Timer::~Timer() {
  // this shall never happen unless program ends.
}

Timer *Timer::instance() {
  if (_timer == NULL)
    _timer = new Timer();
  return _timer;
}

void Timer::updateTimer() {
  uint64_t nextTime;
  nextTime = mach_absolute_time();
  _deltaTime = (nextTime - _lastUpdate) * _orwl_timebase * ORWL_NANO;
  _frameTime += _deltaTime;
  _lastUpdate = nextTime;
}

double Timer::deltaTime() { return _deltaTime; }

double Timer::runTime() {
  return (_lastUpdate - _startingTime) * _orwl_timebase * ORWL_NANO;
}

double Timer::frameTime() { return _frameTime; } // of between frames
void Timer::endFrame() { _frameTime = 0; }       // called when frame ends
