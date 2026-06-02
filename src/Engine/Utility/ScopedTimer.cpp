/*
    ScopedTimer.cpp

    Implementation of a timer that sends a log when leaving scope.
*/

#include "Utility/ScopedTimer.hpp"
#include <iostream>

ScopedTimer::ScopedTimer(const std::string& name)
    : NAME_(name) {}

double ScopedTimer::seconds() const {
    return timer_.seconds();
}

double ScopedTimer::milliseconds() const {
    return timer_.milliseconds();
}

double ScopedTimer::microseconds() const {
    return timer_.microseconds();
}

ScopedTimer::~ScopedTimer() {
    std::clog << NAME_ << ": " << timer_.milliseconds() << " ms\n";
}
