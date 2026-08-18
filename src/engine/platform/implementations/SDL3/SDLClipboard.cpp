/*
    SDLClipboard.hpp

    Implementation of an SDL-implemented clipboard module.
*/

#include "platform/implementations/SDL/SDLClipboard.hpp"
#include <SDL3/SDL.h>

namespace toxico {
    Result<std::string, Error<ClipboardError>> SDLClipboard::getText() const {
        // Get clipboard content
        auto c_str = SDL_GetClipboardText();
        auto str = std::string(c_str);
        SDL_free(c_str);

        // Failed to fetch, return an error
        if (str.empty())
            return {Error<ClipboardError>(ClipboardError::PlatformError, std::string(SDL_GetError()))};

        // Success
        return {str};
    }

    Error<ClipboardError> SDLClipboard::set(const std::string& data) {
        // Attempt to set text
        if (SDL_SetClipboardText(data.c_str())) {
            setFormat(ClipboardFormat::Text);
            return {};
        }

        // Failed
        return {Error<ClipboardError>(ClipboardError::PlatformError, std::string(SDL_GetError()))};
    }
}
