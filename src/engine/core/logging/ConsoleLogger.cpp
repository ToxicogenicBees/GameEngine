/*
    ConsoleLogger.cpp

    Implementation of a console logger.
*/

#include "core/logging/ConsoleLogger.hpp"
#include <iostream>

namespace toxico {
    void ConsoleLogger::processMessage(const std::string& message) noexcept {
        std::clog << message << "\n";
    }

    void ConsoleLogger::dump() noexcept {
        std::flush(std::clog);
    }
}
