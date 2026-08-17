/*
    SDLClipboard.hpp

    Declaration of an SDL-implemented clipboard module.
*/

#pragma once

#include "platform/ClipboardBase.hpp"
#include "foundation/Result.hpp"
#include "foundation/Error.hpp"
#include <string>

namespace toxico {
    class SDLClipboard final : public ClipboardBase {
    public:
        /**
         * @brief Gets the text content stored in the clipboard.
         * 
         * @return The text content stored in the clipboard.
         */
        Result<std::string, Error<ClipboardError>> getText() const final;

        /**
         * @brief Sets the clipboard content to the desired text content.
         * 
         * @param data The string content being set to the clipboard.
         * @return The error state if one occurred, or nothing otherwise.
         */
        Error<ClipboardError> set(const std::string& data) final;
    };
};
