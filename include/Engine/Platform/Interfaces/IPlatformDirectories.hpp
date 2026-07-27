/*
    IPlatformDirectories.hpp

    An interface for fetching platform-specific directory locations.
*/

#pragma once

#include "Platform/Interfaces/IPlatformModule.hpp"
#include "Foundation/Result.hpp"
#include "Foundation/Error.hpp"
#include "Platform/Path.hpp"

namespace toxico {
    enum class DirectoryError {
        None,
        NotFound,
    };

    class IPlatformDirectories : public IPlatformModule {
    public:
        /**
         * @brief Gets the executable directory.
         * 
         * @return The executable directory.
         */
        virtual Result<Path, Error<DirectoryError>> executable() const = 0;

        /**
         * @brief Gets the executable directory.
         * 
         * @return The executable directory.
         */
        virtual Result<Path, Error<DirectoryError>> userData() const = 0;

        /**
         * @brief Gets the executable directory.
         * 
         * @return The executable directory.
         */
        virtual Result<Path, Error<DirectoryError>> temp() const = 0;

        /**
         * @brief Destructor.
         */
        virtual ~IPlatformDirectories() = default;
    };
}