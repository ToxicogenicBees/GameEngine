/*
    STDFile.hpp

    Declaration of a file object implemented using C++ standard methods.
*/

#pragma once

#include "Platform/FileBase.hpp"
#include "Foundation/Result.hpp"
#include "Foundation/Error.hpp"
#include <fstream>
#include <cstdint>
#include <utility>
#include <span>

namespace toxico {
    class STDFile final : public FileBase {
    private:
        std::fstream stream_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param stream The fstream this file reads/writes with
         * @param open_mode The open mode.
         */
        STDFile(std::fstream stream, FileOpenMode open_mode);

        /**
         * @brief Reads data into a buffer from the file.
         * 
         * @param buffer The buffer being read into.
         * @return Info on the size and result of the read.
         */
        Result<std::size_t, Error<FileError>> read(std::span<std::byte> buffer) final;

        /**
         * @brief Reads the entire file's contents into a buffer.
         * 
         * @return Info on the file content and result of the read
         */
        Result<std::vector<std::byte>, Error<FileError>> readAll() final;

        /**
         * @brief Writes data from a buffer into the file.
         * 
         * @param buffer The buffer being writen from.
         * @return Info on the size and result of the write.
         */
        Result<std::size_t, Error<FileError>> write(std::span<std::byte> buffer) final;

        /**
         * @brief Moves the file cursor to a specified position.
         * 
         * @param offset The desired cursor offset.
         * @param origin The desired origin.
         * @return Info on the result of the seek.
         */
        Error<FileError> seek(int64_t offset, SeekOrigin origin) final;

        /**
         * @brief Moves the file cursor to a specified position.
         * 
         * @return Info on the position and result of the check.
         */
        Result<uint64_t, Error<FileError>> tell() final;

        /**
         * @brief Moves the file cursor to a specified position.
         * 
         * @return Info on the size and result of the check.
         */
        Result<uint64_t, Error<FileError>> size() final;

        /**
         * @brief Moves the file cursor to a specified position.
         * 
         * @return Info on the result of the seek.
         */
        Error<FileError> flush() final;

        /**
         * @brief Destructor.
         */
        ~STDFile() final;
    };
}
