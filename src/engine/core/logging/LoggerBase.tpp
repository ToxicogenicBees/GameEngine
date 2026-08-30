/*
    LoggerBase.tpp

    Template implementation of an abstract logger object.
*/

#include <format>

namespace toxico {
    /**
     * @brief Sends a message to the logger.
     * 
     * @param args The items being sent to the log.
     */
    template<Loggable... Args>
    void LoggerBase::log(const Args& ...args) noexcept {
        // Format message
        std::string message;
        ([&](const Args& arg) {
            if (!message.empty())
                message += ' ';

            if constexpr (Stringable<decltype(arg)>)
                message += arg.toString();
            else if constexpr (std::convertible_to<decltype(arg), std::string>)
                message += std::string(arg);
            else
                message += std::format("{}", arg);
        }(args), ...);

        // Process message
        processMessage(message);
    }
}
