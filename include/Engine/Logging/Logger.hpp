/*
    Logger.hpp

    Declaration of a logger class that allows for easy system debugging.
*/

#pragma once

#include "Logging/LogMessage.hpp"
#include <source_location>
#include <fstream>
#include <array>
#include <deque>

class Logger {
private:
    inline static std::deque<LogMessage> buffer_;
    inline static std::array<std::ofstream, 2> logs_;
    inline static std::array<std::string, 2> log_names_;

    /**
     * @brief Constructor (deleted).
     */
    Logger() = delete;

public:
    /**
     * @brief Sends a log.
     * 
     * @param level The log level.
     * @param category The log category.
     * @param message The log message.
     */
    static void log(LogLevel level, LogCategory category, const std::string& message, const std::source_location& location = std::source_location::current());

    /**
     * @brief Initializes the logger.
     */
    static void init();

    /**
     * @brief Shuts down the logger.
     */
    static void shutdown();
};

#define ENGINE_TRACE(cat, msg) \
    Logger::log(LogLevel::TRACE, LogCategory::cat, msg)
#define ENGINE_DEBUG(cat, msg) \
    Logger::log(LogLevel::DEBUG, LogCategory::cat, msg)
#define ENGINE_INFO(cat, msg) \
    Logger::log(LogLevel::INFO, LogCategory::cat, msg)
#define ENGINE_WARN(cat, msg) \
    Logger::log(LogLevel::WARN, LogCategory::cat, msg)
#define ENGINE_ERROR(cat, msg) \
    Logger::log(LogLevel::ERROR, LogCategory::cat, msg)
#define ENGINE_FATAL(cat, msg) \
    Logger::log(LogLevel::FATAL, LogCategory::cat, msg)
