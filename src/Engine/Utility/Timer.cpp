/*
    Timer.cpp

    Implementation of a timer that keeps track of elapsed time from the OS.
*/

#include "Utility/Timer.hpp"

void Timer::reset() {
    prev_sample_ = Clock::now();
}

double Timer::seconds() const {
    return 1e-6 * microseconds();
}

double Timer::milliseconds() const {
    return 1e-3 * microseconds();
}

double Timer::microseconds() const {
    return std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() - prev_sample_).count();
}
