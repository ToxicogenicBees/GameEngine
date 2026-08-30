/*
    LoggerBase.tpp

    Template implementation of an abstract logger object.
*/

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
            else
                message += std::string_view(arg);
        }(args), ...);

        // Process message
        processMessage(message);
    }
}
