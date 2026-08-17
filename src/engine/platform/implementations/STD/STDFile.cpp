/*
    STDFile.cpp

    Implementation of a file object implemented using C++ standard methods.
*/

#include "platform/Implementations/STD/STDFile.hpp"
#include <filesystem>
#include <fstream>

namespace toxico {
    STDFile::STDFile(std::fstream stream, FileOpenMode open_mode)
        : FileBase(open_mode),
          stream_(std::move(stream))
    {}

    Result<size_t, Error<FileError>> STDFile::read(std::span<std::byte> buffer) {
        if (!canRead())
            return Error<FileError>(FileError::PermissionDenied, "Cannot read from write-only file");

        stream_.read(reinterpret_cast<char*>(buffer.data()), static_cast<std::streamsize>(buffer.size()));

        const auto bytes_read = static_cast<size_t>(stream_.gcount());

        if (stream_.bad())
            return Error<FileError>(FileError::IOError, "Could not read bytes");

        return bytes_read;
    }

    Result<std::vector<std::byte>, Error<FileError>> STDFile::readAll() {
        auto file_size = size();
        if (!file_size)
            return std::move(file_size.error());

        {
            auto result = seek(0, SeekOrigin::Begin);
            if (!result)
                return std::move(result);
        }
        
        std::vector<std::byte> buffer(*file_size);

        auto read_result = read(buffer);

        if (!read_result)
            return std::move(read_result.error());

        buffer.resize(*read_result);

        return buffer;
    }

    Result<size_t, Error<FileError>> STDFile::write(std::span<std::byte> buffer) {
        if (!canWrite())
            return Error<FileError>(FileError::PermissionDenied, "Cannot write to read-only file");

        stream_.write(reinterpret_cast<const char*>(buffer.data()), buffer.size());

        if (stream_.bad())
            return Error<FileError>(FileError::IOError, "Could not write bytes");

        return buffer.size_bytes();
    }

    Error<FileError> STDFile::seek(int64_t offset, SeekOrigin origin) {
        auto get_origin = [origin]() {
            switch(origin) {
            case SeekOrigin::Begin:
                return std::ios::beg;
            case SeekOrigin::End:
                return std::ios::end;
            case SeekOrigin::Current:
                return std::ios::cur;
            default:
                return std::ios::beg;
            }
        };

        stream_.clear();

        if (canRead())
            stream_.seekg(offset, get_origin());
        if (canWrite())
            stream_.seekp(offset, get_origin());

        if (stream_.fail())
            return Error<FileError>(FileError::IOError, "Could not seek file");
        
        return Error<FileError>(FileError::None, "No error recorded");
    }

    Result<uint64_t, Error<FileError>> STDFile::tell() {
        std::fstream::pos_type pos;
        if (canRead())
            pos = stream_.tellg();
        else if (canWrite())
            pos = stream_.tellp();

        if (pos == std::fstream::pos_type(-1))
            return Error<FileError>(FileError::IOError, "Cannot tell cursor position");
        
        return static_cast<uint64_t>(pos);
    }

    Result<uint64_t, Error<FileError>> STDFile::size() {
        auto cursor = tell();
        if (!cursor)
            return std::move(cursor.error());

        {
            auto result = seek(0, SeekOrigin::End);
            if (!result)
                return std::move(result);
        }

        auto size = tell();
        if (!size)
            return std::move(size.error());

        {
            auto result = seek(*cursor, SeekOrigin::Begin);
            if (!result)
                return std::move(result);
        }

        return *size;
    }

    Error<FileError> STDFile::flush() {
        stream_.flush();

        if (stream_.fail())
            return Error<FileError>(FileError::IOError, "Could not flush file");

        return {};
    }

    STDFile::~STDFile() {
        stream_.close();
    }
}
