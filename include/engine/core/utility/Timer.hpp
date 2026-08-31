/*
    Timer.hpp

    Declaration of a timer that keeps track of elapsed time from the OS.
*/

#pragma once

#include "foundation/utility/fp_type.hpp"
#include <chrono>

namespace toxico {
    class Timer {
    private:
        using Clock = std::chrono::steady_clock;
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
        fp_type seconds() const;

        /**
         * @brief Gets the elapsed time of the counter, in milliseconds.
         * 
         * @return The number of milliseconds elapsed.
         */
        fp_type milliseconds() const;

        /**
         * @brief Gets the elapsed time of the counter, in microseconds.
         * 
         * @return The number of microseconds elapsed.
         */
        fp_type microseconds() const;
    };
}
