/*
    IMouse.hpp

    An interface for a mouse.
*/

#pragma once

#include "platform/devices/interfaces/IDevice.hpp"
#include "platform/devices/enums/MouseCodes.hpp"
#include "foundation/math/Vector.hpp"

namespace toxico {
    class IMouse : public IDevice {
        /**
         * @brief Gets if a button is being pressed.
         * 
         * @return If the button is being pressed.
         */
        virtual bool pressed(MouseCode button) const noexcept = 0;

        /**
         * @brief Gets the position of the mouse.
         * 
         * @return The position of the mouse.
         */
        virtual Vector2i position() const noexcept = 0;
    };
}
