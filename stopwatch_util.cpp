#include <sys/time.h>
#include <iostream>
#include "hamkoutil/stopwatch_util.hpp"

using namespace std;
static double s_tmptime[MAX_TIMER_NUM] = {}; // [s]

void stopwatch_start(int index)
{
    if (index >= MAX_TIMER_NUM) {
        cout << "INVALID TIMER NUM, IGNORED: MAX_TIMER_NUM is " << MAX_TIMER_NUM<< endl;
        return;
    }
    struct timeval tim;  
    gettimeofday(&tim, NULL);  
    s_tmptime[index] = tim.tv_sec+(tim.tv_usec / 1000000.0);  
}

double stopwatch_end(int index)
{
    if (index >= MAX_TIMER_NUM) {
        cout << "INVALID TIMER NUM, IGNORED: MAX_TIMER_NUM is " << MAX_TIMER_NUM<< endl;
        return -1;
    }
    struct timeval tim;  
    gettimeofday(&tim, NULL);  
    return tim.tv_sec+(tim.tv_usec / 1000000.0) - s_tmptime[index];
}

double get_clock_now(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + (double)tv.tv_usec*1e-6;
}

