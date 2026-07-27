/*
    WindowsDirectories.hpp

    Declaration of Windows-specific file directories.
*/

#pragma once

#include "Platform/Interfaces/IPlatformDirectories.hpp"
#include "Foundation/Result.hpp"
#include "Foundation/Error.hpp"
#include "Platform/Path.hpp"

namespace toxico {
    class WindowsDirectories : public IPlatformDirectories {
    public:
        /**
         * @brief Gets the executable directory.
         * 
         * @return The executable directory.
         */
        Result<Path, Error<DirectoryError>> executable() const final;

        /**
         * @brief Gets the executable directory.
         * 
         * @return The executable directory.
         */
        Result<Path, Error<DirectoryError>> userData() const final;

        /**
         * @brief Gets the executable directory.
         * 
         * @return The executable directory.
         */
        Result<Path, Error<DirectoryError>> temp() const final;
    };
}