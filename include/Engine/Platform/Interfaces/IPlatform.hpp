/*
    IPlatform.hpp

    An interface for a platform, containing platform-specific OS-level functionality
*/

#pragma once

#include "Platform/Interfaces/IPlatformDirectories.hpp"
#include "Platform/Interfaces/IFileSystem.hpp"
#include "Platform/Interfaces/IClipboard.hpp"

namespace toxico {
    class IPlatform {
    public:
        /**
         * @brief Gets the file system of this platform.
         * 
         * @return The file system of this platform.
         */
        virtual IFileSystem& files() = 0;

        /**
         * @brief Gets the file system of this platform.
         * 
         * @return The file system of this platform.
         */
        virtual IClipboard& clipboard() = 0;

        /**
         * @brief Gets the system directories of this platform.
         * 
         * @return The system directories of this platform.
         */
        virtual IPlatformDirectories& dirs() = 0;

        /**
         * @brief Destructor.
         */
        virtual ~IPlatform() = default;
    };
}
