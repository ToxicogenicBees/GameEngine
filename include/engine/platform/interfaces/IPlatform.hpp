/*
    IPlatform.hpp

    An interface for an OS platform.
*/

#pragma once

namespace toxico {
    class IPlatform {
    public:
        /**
         * @brief Polls the platform for an event.
         * 
         * @return If an event was successfully polled.
         */
        virtual bool pollEvent() = 0;
    };
}
