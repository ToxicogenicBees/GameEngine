/*
    LogMessage.cpp

    Implementation of a log message, containing information on engine runtime.
*/

#include "Logging/LogMessage.hpp"
#include <string_view>
#include <iomanip>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>

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

    std::string categoryToString(LogCategory level) {
        switch(level) {
            case (LogCategory::CORE):
                return "[CORE]";
            case (LogCategory::RENDERER):
                return "[RENDERER]";
            case (LogCategory::ASSET):
                return "[ASSET]";
            case (LogCategory::RESOURCE):
                return "[RESOURCE]";
            case (LogCategory::INPUT):
                return "[INPUT]";
            case (LogCategory::SCENE):
                return "[SCENE]";
            case (LogCategory::GPU):
                return "[GPU]";
            case (LogCategory::PHYSICS):
                return "[PHYSICS]";
            case (LogCategory::UI):
                return "[UI]";
            default:
                return "[NONE]";
        }
    }

    std::string time() {
        // Get hour, minute, and seconds
        auto now = std::time(0);
        auto local_time = std::localtime(&now);

        std::stringstream ss;
        ss << std::setw(2) << std::setfill('0') << local_time->tm_hour << ":"
           << std::setw(2) << std::setfill('0') << local_time->tm_min << ":"
           << std::setw(2) << std::setfill('0') << local_time->tm_sec;

        return ss.str();
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
      MESSAGE_(levelToString(level) + " " + categoryToString(category) + "\t" + time() + " " + message + " - " + std::string(sourceFileName(location)) + ":" + std::to_string(location.line()))
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
