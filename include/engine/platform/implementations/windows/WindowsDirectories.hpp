/*
    WindowsDirectories.hpp

    Declaration of Windows-specific file directories.
*/

#pragma once

#include "platform/interfaces/IPlatformDirectories.hpp"
#include "foundation/Result.hpp"
#include "foundation/Error.hpp"
#include "platform/Path.hpp"

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