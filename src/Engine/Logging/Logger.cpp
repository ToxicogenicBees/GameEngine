/*
    Logger.cpp

    Implementation of a logger class that allows for easy system debugging.
*/

#include "Logging/Logger.hpp"
#include <iostream>
#include <vector>
#include <deque>

namespace {
    constexpr size_t MAX_BUFFER_SIZE = 5000;
}

void Logger::log(LogLevel level, LogCategory category, const std::string& message, const std::source_location& location ) {
    // Create message
    LogMessage msg(level, category, message, location);

    // Buffer for later purposes
    buffer_.emplace_back(msg);
    if (buffer_.size() > MAX_BUFFER_SIZE)
        buffer_.pop_front();

    // @TODO: Write to log file
    std::clog << msg.message() << "\n";

    // Exit if requires
    if (level == LogLevel::FATAL)
        exit(-1);
}
