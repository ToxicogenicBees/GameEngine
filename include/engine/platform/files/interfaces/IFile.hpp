/*
    IFile.hpp

    An interface for a file.
*/

#pragma once

#include "foundation/utility/Result.hpp"
#include "foundation/utility/Error.hpp"
#include <cstdint>
#include <utility>
#include <span>

namespace toxico {
    enum class FileError {
        None,
        NotFound,
        PermissionDenied,
        InvalidPath,
        InvalidHandle,
        IOError,
        EndOfFile,
    };

    enum class FileOpenMode {
        Read,
        Write,
        ReadWrite,
        Append
    };

    enum class SeekOrigin {
        Begin,
        Current,
        End,
    };

    class IFile {
    public:
        /**
         * @brief Reads data into a buffer from the file.
         * 
         * @param buffer The buffer being read into.
         * @return Info on the size and result of the read.
         */
        virtual Result<std::size_t, Error<FileError>> read(std::span<std::byte> buffer) = 0;

        /**
         * @brief Reads the entire file's contents into a buffer.
         * 
         * @return Info on the file content and result of the read
         */
        virtual Result<std::vector<std::byte>, Error<FileError>> readAll() = 0;

        /**
         * @brief Writes data from a buffer into the file.
         * 
         * @param buffer The buffer being writen from.
         * @return Info on the size and result of the write.
         */
        virtual Result<std::size_t, Error<FileError>> write(std::span<std::byte> buffer) = 0;

        /**
         * @brief Moves the file cursor to a specified position.
         * 
         * @param offset The desired cursor offset.
         * @param origin The desired origin.
         * @return Info on the result of the seek.
         */
        virtual Error<FileError> seek(int64_t offset, SeekOrigin origin) = 0;

        /**
         * @brief Moves the file cursor to a specified position.
         * 
         * @return Info on the position and result of the check.
         */
        virtual Result<uint64_t, Error<FileError>> tell() = 0;

        /**
         * @brief Moves the file cursor to a specified position.
         * 
         * @return Info on the size and result of the check.
         */
        virtual Result<uint64_t, Error<FileError>> size() = 0;

        /**
         * @brief Moves the file cursor to a specified position.
         * 
         * @return Info on the result of the seek.
         */
        virtual Error<FileError> flush() = 0;

        /**
         * @brief Gets the open mode for the file.
         * 
         * @return The open mode for the file.
         */
        virtual FileOpenMode openMode() const = 0;

        /**
         * @brief Gets if the file can be read from.
         * 
         * @returns The read state of the file.
         */
        virtual bool canRead() const = 0;

        /**
         * @brief Gets if the file can be written to.
         * 
         * @returns The write state of the file.
         */
        virtual bool canWrite() const = 0;

        /**
         * @brief Destructor.
         */
        virtual ~IFile() = default;
    };
}
