/*
    Error.hpp

    Declaration of an error class.
*/

#pragma once

#include <string>
#include <vector>
#include <concepts>

namespace toxico {
    template<typename Code>
    requires std::is_enum_v<Code>
    class Error {
        private:
            std::vector<std::string> context_;
            std::string message_;
            Code code_;

        public:
            /**
             * @brief Constructor.
             * 
             * @param code The desired error code.
             * @param message The desired error message.
             */
            Error(Code code, std::string message);

            /**
             * @brief Constructor.
             * 
             * @param code The desired error code.
             */
            Error(Code code = Code::None);

            /**
             * @brief Adds context to the error.
             * 
             * @param context The additional context.
             * @return Reference to this error.
             */
            Error<Code>& addContext(std::string context);

            /**
             * @brief Gets all the context of this error.
             * 
             * @return This error's context.
             */
            const std::vector<std::string>& context() const;

            /**
             * @brief Gets the error code of this error.
             * 
             * @return The error code for this error.
             */
            Code code() const;

            /**
             * @brief Gets the error message for this error.
             * 
             * @return The error message for this error.
             */
            const std::string& what() const;

            /**
             * @brief Boolean conversion, returning false if an error other than "None" was recorded.
             */
            explicit operator bool() const;

            /**
             * @brief Destructor.
             */
            virtual ~Error() = default;
    };
}

#include "foundation/utility/Error.tpp"
