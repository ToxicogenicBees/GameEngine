/*
    PlatformFactory.hpp

    Declaration of a platform factory, building a platform for specific build systems.
*/

#pragma once

#include "Platform/Platform.hpp"
#include <memory>

namespace toxico {
    class PlatformFactory {
    private:
        /**
         * @brief Constructor. (deleted)
         */
        PlatformFactory() = delete;

    public:
        /**
         * @brief Creates a new platform object for the appropriate system.
         * 
         * @return The constructed platform object.
         */
        static std::unique_ptr<Platform> create();
    };
}
