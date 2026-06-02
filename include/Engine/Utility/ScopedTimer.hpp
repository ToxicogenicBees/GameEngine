/*
    ScopedTimer.hpp

    Declaration of a timer that sends a log when leaving scope.
*/

#pragma once

#include "Utility/Timer.hpp"
#include <string>

class ScopedTimer {
private:
    const std::string NAME_;
    Timer timer_;

public:
    /**
     * @brief Constructor.
     */
    ScopedTimer(const std::string& name);

    /**
     * @brief Gets the elapsed time of the counter, in seconds.
     * 
     * @return The number of seconds elapsed.
     */
    double seconds() const;

    /**
     * @brief Gets the elapsed time of the counter, in milliseconds.
     * 
     * @return The number of milliseconds elapsed.
     */
    double milliseconds() const;

    /**
     * @brief Gets the elapsed time of the counter, in microseconds.
     * 
     * @return The number of microseconds elapsed.
     */
    double microseconds() const;

    /**
     * @brief Destructor.
     */
    ~ScopedTimer();
};
