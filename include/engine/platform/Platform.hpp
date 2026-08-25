/*
    Platform.hpp

    Declaration of the operating-system engine layer.
*/

#pragma once

#include "platform/clipboard/interfaces/IClipboard.hpp"
#include "platform/files/interfaces/IDirectories.hpp"
#include "platform/files/interfaces/IFileSystem.hpp"
#include "platform/interfaces/IPlatformModule.hpp"
#include "foundation/containers/ModuleRegistry.hpp"
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
        IDirectories& dirs();
    };
}

#include "platform/Platform.tpp"
