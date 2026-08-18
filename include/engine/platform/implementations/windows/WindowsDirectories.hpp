/*
    WindowsDirectories.hpp

    Declaration of Windows-specific file directories.
*/

#pragma once

#include "platform/files/interfaces/IDirectories.hpp"
#include "platform/files/Path.hpp"
#include "foundation/Result.hpp"
#include "foundation/Error.hpp"

namespace toxico {
    class WindowsDirectories : public IDirectories {
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