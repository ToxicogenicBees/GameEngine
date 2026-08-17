/*
    IClipboard.hpp

    An interface for the OS clipboard.
*/

#pragma once

#include "platform/interfaces/IPlatformModule.hpp"
#include "foundation/Result.hpp"
#include "foundation/Error.hpp"
#include <string>

namespace toxico {
    enum class ClipboardFormat {
        None,
        Text,
        Image,
        Binary
    };

    enum class ClipboardError {
        None,
        Empty,
        UnsupportedFormat,
        AccessDenied,
        PlatformError
    };

    class IClipboard : public IPlatformModule {
    public:
        /**
         * @brief Gets the current clipboard data format.
         * 
         * @return The current clipboard data format.
         */
        virtual ClipboardFormat format() const = 0;

        /**
         * @brief Gets the text content stored in the clipboard.
         * 
         * @return The text content stored in the clipboard.
         */
        virtual Result<std::string, Error<ClipboardError>> getText() const = 0;

        /**
         * @brief Sets the clipboard content to the desired text content.
         * 
         * @param data The string content being set to the clipboard.
         * @return The error state if one occurred, or nothing otherwise.
         */
        virtual Error<ClipboardError> set(const std::string& data) = 0;
    };
}
