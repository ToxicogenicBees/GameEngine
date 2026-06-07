/*
    LogMessage.cpp

    Implementation of a log message, containing information on engine runtime.
*/

#include "Logging/LogMessage.hpp"
#include <string_view>

namespace {
    std::string levelToString(LogLevel level) {
        switch(level) {
            case (LogLevel::TRACE):
                return "[TRACE]";
            case (LogLevel::DEBUG):
                return "[DEBUG]";
            case (LogLevel::INFO):
                return "[INFO]";
            case (LogLevel::WARN):
                return "[WARN]";
            case (LogLevel::ERROR):
                return "[ERROR]";
            case (LogLevel::FATAL):
                return "[FATAL]";
            default:
                return "[NONE]";
        }
    }

    inline std::string_view sourceFileName(const std::source_location& location) {
        std::string_view path = location.file_name();

        const auto pos = path.find_last_of("/\\");

        return pos == std::string_view::npos
            ? path
            : path.substr(pos + 1);
    }
}

LogMessage::LogMessage(LogLevel level, LogCategory category, const std::string& message, const std::source_location& location)
    : LEVEL_(level),
      CATEGORY_(category), 
      MESSAGE_(levelToString(level) + " " + std::string(sourceFileName(location)) + "\n" + message)
{}

LogLevel LogMessage::level() const {
    return LEVEL_;
}

LogCategory LogMessage::category() const {
    return CATEGORY_;
}

std::string LogMessage::message() const {
    return MESSAGE_;
}
