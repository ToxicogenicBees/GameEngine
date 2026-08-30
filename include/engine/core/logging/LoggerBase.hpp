/*
    LoggerBase.hpp

    Declaration of an abstract logger object.
*/

#pragma once

#include "core/interfaces/ICoreModule.hpp"
#include "core/logging/concepts/Loggable.hpp"
#include <concepts>
#include <string>

namespace toxico {
    class LoggerBase : public ICoreModule {
    protected:
        /**
         * @brief Processes a message.
         * 
         * @param message The message being processed.
         */
        virtual void processMessage(const std::string& message) noexcept = 0;

    public:
        /**
         * @brief Sends a message to the logger.
         * 
         * @param args The items being sent to the log.
         */
        template<Loggable... Args>
        void log(const Args& ...args) noexcept;

        /**
         * @brief Dumps all buffered content into the log.
         */
        virtual void dump() noexcept = 0;
    };
}

#include "core/logging/LoggerBase.tpp"
