/*
    Platform.hpp

    Declaration of the operating-system engine layer.
*/

#pragma once

#include "Platform/Interfaces/IPlatform.hpp"
#include "Platform/Interfaces/IPlatformModule.hpp"
#include "Foundation/ModuleRegistry.hpp"
#include "Platform/Interfaces/IFileSystem.hpp"
#include "Platform/Interfaces/IClipboard.hpp"
#include <memory>

namespace toxico {
    class Platform final : public IPlatform {
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
        template<typename Interface, typename Implementation>
        void addModule(std::unique_ptr<Implementation> module);

        /**
         * @brief Gets the file system of this platform.
         * 
         * @return The file system of this platform.
         */
        IFileSystem& files() final;

        /**
         * @brief Gets the file system of this platform.
         * 
         * @return The file system of this platform.
         */
        IClipboard& clipboard() final;

        /**
         * @brief Gets the system directories of this platform.
         * 
         * @return The system directories of this platform.
         */
        IPlatformDirectories& dirs() final;
    };
}

#include "Platform/Platform.tpp"
