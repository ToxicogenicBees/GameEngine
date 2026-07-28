/*
    Platform.hpp

    Declaration of the operating-system engine layer.
*/

#pragma once

#include "Platform/Interfaces/IPlatformModule.hpp"
#include "Platform/Interfaces/IPlatformDirectories.hpp"
#include "Platform/Interfaces/IFileSystem.hpp"
#include "Platform/Interfaces/IClipboard.hpp"
#include "Foundation/ModuleRegistry.hpp"
#include <memory>

namespace toxico {
    class Platform {
    private:
        ModuleRegistry<IPlatformModule> modules_;

    public:
        /**
         * @brief Constructor.
         */
        Platform() = default;

        /**
         * @brief Adds a platform module to the object.
         * 
         * @param module The module being added.
         */
        template<typename Interface, typename Implementation = Interface>
        void addModule(std::unique_ptr<Implementation> module);

        /**
         * @brief Gets the file system of this platform.
         * 
         * @return The file system of this platform.
         */
        IFileSystem& files();

        /**
         * @brief Gets the file system of this platform.
         * 
         * @return The file system of this platform.
         */
        IClipboard& clipboard();

        /**
         * @brief Gets the system directories of this platform.
         * 
         * @return The system directories of this platform.
         */
        IPlatformDirectories& dirs();
    };
}

#include "Platform/Platform.tpp"
