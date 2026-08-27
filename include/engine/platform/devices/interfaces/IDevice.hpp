/*
    IDevice.hpp

    An interface for a device.
*/

#pragma once

#include <string>

namespace toxico {
    class IDevice {
    public:
        /**
         * @brief Gets the name of a device.
         * 
         * @return The name of the device.
         */
        virtual std::string name() const noexcept = 0;

        /**
         * @brief Destructor
         */
        virtual ~IDevice() = default;
    };
}
