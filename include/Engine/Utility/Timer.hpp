/*
    Timer.hpp

    Declaration of a timer that keeps track of elapsed time from the OS.
*/

#pragma once

#include <chrono>

class Timer {
private:
    using Clock = std::chrono::high_resolution_clock;
    using Sample = std::chrono::time_point<Clock>;

    Sample prev_sample_ = Clock::now();

public:
    /**
     * @brief Constructor.
     */
    Timer() = default;

    /**
     * @brief Resets the timer.
     */
    void reset();

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
};
