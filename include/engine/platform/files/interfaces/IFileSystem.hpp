/*
    IFilesystem.hpp

    An interface for reading/writing files to the OS
*/

#pragma once

#include "platform/interfaces/IPlatformModule.hpp"
#include "platform/files/interfaces/IFile.hpp"
#include "platform/files/Path.hpp"
#include "foundation/utility/Result.hpp"
#include "foundation/utility/Error.hpp"
#include <memory>

namespace toxico {
    enum FileSystemError {
        None,
        FailToOpen,
        PermissionDenied,
        DirectoryNotEmpty,
    };

    class IFileSystem : public IPlatformModule {
    public:
        /**
         * @brief Gets if the specified path exists.
         * 
         * @param path The desired path.
         * @return Info on if the path was found and the result of the search.
         */
        virtual Result<bool, Error<FileSystemError>> exists(const Path& path) const = 0;

        /**
         * @brief Removes the specific file.
         * 
         * @param file The path to the desired file.
         * @return Info on the result of the removal.
         */
        virtual Error<FileSystemError> removeFile(const Path& file) = 0;

        /**
         * @brief Removes the specific directory.
         *        Fails to remove non-empty directories.
         * 
         * @param file The path to the desired directory.
         * @return Info on the result of the removal.
         */
        virtual Error<FileSystemError> removeDirectory(const Path& directory) = 0;

        /**
         * @brief Creates a specified directory.
         *        Directories will be created recursively if they don't already exist.
         * 
         * @param directory The path to the new directory.
         * @return Info on the result of the creation.
         */
        virtual Error<FileSystemError> createDirectories(const Path& directory) = 0;

        /**
         * @brief Copies the specific file.
         * 
         * @param source The source file being copied.
         * @param destination The destination of the copied file.
         * @return Info on the result of the copy.
         */
        virtual Error<FileSystemError> copy(const Path& source, const Path& destination) = 0;

        /**
         * @brief Moves the specific file.
         * 
         * @param source The source file being move.
         * @param destination The destination of the file.
         * @return Info on the result of the move.
         */
        virtual Error<FileSystemError> move(const Path& source, const Path& destination) = 0;

        /**
         * @brief Gets all files in the specified directory.
         * 
         * @param directory The directory being enumerated over.
         * @return Info on the found files and the result of the query.
         */
        virtual Result<std::vector<Path>, Error<FileSystemError>> enumerate(const Path& directory) const = 0;

        /**
         * @brief Opens the specified file.
         * 
         * @param file The path to the desired file.
         * @return Info on opened file and the result of the removal.
         */
        virtual Result<std::unique_ptr<IFile>, Error<FileSystemError>> open(const Path& file, FileOpenMode mode = FileOpenMode::ReadWrite) = 0;
    };
}
