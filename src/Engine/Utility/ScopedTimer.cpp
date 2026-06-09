/*
    ScopedTimer.cpp

    Implementation of a timer that sends a log when leaving scope.
*/

#include "Utility/ScopedTimer.hpp"
#include "Logging/Logger.hpp"
#include <format>

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
    ENGINE_DEBUG(CORE, std::format(
        "{}: {}",
        NAME_,
        timer_.milliseconds()
    ));
}
