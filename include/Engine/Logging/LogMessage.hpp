/*
    LogMessage.hpp

    Declaration of a log message, containing information on engine runtime.
*/

#include <string>
#include <source_location>

enum class LogLevel {
    NONE,
    TRACE,
    DEBUG,
    INFO,
    WARN,
    ERROR,
    FATAL,
};

enum class LogCategory {
    NONE,
    CORE,
    RENDERER,
    ASSET,
    RESOURCE,
    INPUT,
    SCENE,
    GPU,
    PHYSICS,
    UI,
};

class LogMessage {
private:
    const std::string MESSAGE_;
    const LogCategory CATEGORY_;
    const LogLevel LEVEL_;

public:
    /**
     * @brief Constructor.
     * 
     * @param level The log level.
     * @param category The log category.
     * @param message The log message.
     */
    LogMessage(LogLevel level, LogCategory category, const std::string& message, const std::source_location& location);

    /**
     * @brief Constructor.
     */
    LogMessage() = default;

    /**
     * @brief Gets the level of this log.
     * 
     * @return The level of this log.
     */
    LogLevel level() const;

    /**
     * @brief Gets the category of this log.
     * 
     * @return The category of this log.
     */
    LogCategory category() const;

    /**
     * @brief Gets the message of this log.
     * 
     * @return The message of this log.
     */
    std::string message() const;
};