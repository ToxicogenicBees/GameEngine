/*
    Timer.cpp

    Implementation of a timer that keeps track of elapsed time from the OS.
*/

#include "core/utility/Timer.hpp"

namespace toxico {
    void Timer::reset() {
        prev_sample_ = Clock::now();
    }

    fp_type Timer::seconds() const {
        return fp_type{1e-6} * microseconds();
    }

    fp_type Timer::milliseconds() const {
        return fp_type{1e-3} * microseconds();
    }

    fp_type Timer::microseconds() const {
        return std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() - prev_sample_).count();
    }
}
