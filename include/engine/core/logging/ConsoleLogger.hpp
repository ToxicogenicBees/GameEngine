/*
    ConsoleLogger.hpp

    Declaration of a console logger.
*/

#pragma once

#include "core/logging/LoggerBase.hpp"

namespace toxico {
    class ConsoleLogger final : public LoggerBase {
    protected:
        /**
         * @brief Processes a message.
         * 
         * @param message The message being processed.
         */
        void processMessage(const std::string& message) noexcept final;

    public:
        /**
         * @brief Dumps all buffered content into the log.
         */
        void dump() noexcept final;
    };
}
