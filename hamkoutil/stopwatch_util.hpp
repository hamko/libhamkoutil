#ifndef STOPWATCH_UTIL_HPP_INCLUDED
#define STOPWATCH_UTIL_HPP_INCLUDED

#define MAX_TIMER_NUM 256
extern double stopwatch_end(int index);
extern void stopwatch_start(int index);
extern double get_clock_now(void);

#endif
