/*
    STDFileSystem.hpp

    Declaration of a file system object implemented using C++ standard methods.
*/

#pragma once

#include "platform/interfaces/IFileSystem.hpp"
#include "foundation/Result.hpp"
#include "foundation/Error.hpp"
#include "platform/Path.hpp"
#include <memory>

namespace toxico {
    class STDFileSystem final : public IFileSystem {
    public:
        /**
         * @brief Gets if the specified path exists.
         * 
         * @param path The desired path.
         * @return Info on if the path was found and the result of the search.
         */
        Result<bool, Error<FileSystemError>> exists(const Path& path) const final;

        /**
         * @brief Removes the specific file.
         * 
         * @param file The path to the desired file.
         * @return Info on the result of the removal.
         */
        Error<FileSystemError> removeFile(const Path& file) final;

        /**
         * @brief Removes the specific directory.
         *        Fails to remove non-empty directories.
         * 
         * @param file The path to the desired directory.
         * @return Info on the result of the removal.
         */
        Error<FileSystemError> removeDirectory(const Path& directory) final;

        /**
         * @brief Creates a specified directory.
         *        Directories will be created recursively if they don't already exist.
         * 
         * @param directory The path to the new directory.
         * @return Info on the result of the creation.
         */
        Error<FileSystemError> createDirectories(const Path& directory) final;

        /**
         * @brief Copies the specific file.
         * 
         * @param source The source file being copied.
         * @param destination The destination of the copied file.
         * @return Info on the result of the copy.
         */
        Error<FileSystemError> copy(const Path& source, const Path& destination) final;

        /**
         * @brief Moves the specific file.
         * 
         * @param source The source file being move.
         * @param destination The destination of the file.
         * @return Info on the result of the move.
         */
        Error<FileSystemError> move(const Path& source, const Path& destination) final;

        /**
         * @brief Gets all files in the specified directory.
         * 
         * @param directory The directory being enumerated over.
         * @return Info on the found files and the result of the query.
         */
        Result<std::vector<Path>, Error<FileSystemError>> enumerate(const Path& directory) const final;

        /**
         * @brief Opens the specified file.
         * 
         * @param file The path to the desired file.
         * @return Info on opened file and the result of the removal.
         */
        Result<std::unique_ptr<IFile>, Error<FileSystemError>> open(const Path& file, FileOpenMode mode = FileOpenMode::ReadWrite) final;
    };
}
