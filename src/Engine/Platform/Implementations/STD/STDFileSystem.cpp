/*
    STDFileSystem.cpp

    Implementation of a file system object implemented using C++ standard methods.
*/

#include "Platform/Implementations/STD/STDFileSystem.hpp"
#include "Platform/Implementations/STD/STDFile.hpp"
#include <filesystem>
#include <fstream>

namespace toxico {
    Result<bool, Error<FileSystemError>> STDFileSystem::exists(const Path& path) const {
        return std::filesystem::exists(path.native());
    }

    Error<FileSystemError> STDFileSystem::removeFile(const Path& file) {
        std::filesystem::remove(file.native());
        return {};
    }

    Error<FileSystemError> STDFileSystem::removeDirectory(const Path& directory) {
        auto children = enumerate(directory);
        if (!children)
            return std::move(children.error());

        if (children->empty())
            return Error<FileSystemError>(FileSystemError::DirectoryNotEmpty, "Cannot delete a non-empty directory");

        std::filesystem::remove(directory.native());
        return {};
    }

    Error<FileSystemError> STDFileSystem::createDirectories(const Path& directory) {
        std::filesystem::create_directories(directory.native());
        return {};
    }

    Error<FileSystemError> STDFileSystem::copy(const Path& source, const Path& destination) {
        std::filesystem::copy(source.native(), destination.native());
        return {};
    }

    Error<FileSystemError> STDFileSystem::move(const Path& source, const Path& destination) {
        std::filesystem::copy(source.native(), destination.native());
        std::filesystem::remove(source.native());
        return {};
    }

    Result<std::vector<Path>, Error<FileSystemError>> STDFileSystem::enumerate(const Path& directory) const {
        std::vector<Path> paths;
        for (auto& path : std::filesystem::directory_iterator(directory.native()))
            paths.emplace_back(Path{path});

        return paths;
    }

    Result<std::unique_ptr<IFile>, Error<FileSystemError>> STDFileSystem::open(const Path& file, FileOpenMode mode) {
        // Fetch open mode
        std::ios::openmode open_mode;
        switch(mode) {
        case FileOpenMode::Read:
            open_mode = std::ios::in;
            break;
        case FileOpenMode::Write:
            open_mode = std::ios::out;
            break;
        case FileOpenMode::ReadWrite:
            open_mode = std::ios::in | std::ios::out;
            break;
        case FileOpenMode::Append:
            open_mode = std::ios::in | std::ios::app;
            break;
        }

        // Open the filestream
        std::fstream file_stream(file.native(), open_mode);
        if (!file_stream)
            return Error<FileSystemError>(FileSystemError::FailToOpen, "Failed to open file");

        // Create and return file
        return {std::make_unique<STDFile>(std::move(file_stream), mode)};
    }
}
