/*
    ClipboardBase.hpp

    Declaration of a base abstract clipboard.
*/

#pragma once

#include "platform/clipboard/interfaces/IClipboard.hpp"

namespace toxico {
    class ClipboardBase : public IClipboard {
        private:
            ClipboardFormat format_ = ClipboardFormat::None;

        public:
            /**
             * @brief Sets the clipboard format.
             * 
             * @param format The desired format.
             */
            void setFormat(ClipboardFormat format);

            /**
             * @brief Gets the current clipboard data format.
             * 
             * @return The current clipboard data format.
             */
            ClipboardFormat format() const final;
    };
}
