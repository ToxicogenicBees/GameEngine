/*
    WindowsDirectories.cpp

    Implementation of Windows-specific file directories.
*/

#include "platform/Implementations/windows/WindowsDirectories.hpp"
#include <windows.h>
#include <filesystem>
#include <shlobj.h>

namespace toxico {
    Result<Path, Error<DirectoryError>> WindowsDirectories::executable() const {
        std::wstring buffer(MAX_PATH, L'\0');

        DWORD length = 0;

        while (true) {
            length = GetModuleFileNameW(
                nullptr,
                buffer.data(),
                static_cast<DWORD>(buffer.size())
            );

            if (length == 0) {
                return Error<DirectoryError>(
                    DirectoryError::NotFound,
                    "Failed to get executable path"
                );
            }

            // Buffer was too small
            if (length >= buffer.size() - 1) {
                buffer.resize(buffer.size() * 2);
                continue;
            }

            break;
        }

        buffer.resize(length);

        std::filesystem::path executablePath(buffer);

        return Path(executablePath.parent_path());
    }

    Result<Path, Error<DirectoryError>> WindowsDirectories::userData() const {
        PWSTR raw_path = nullptr;

        HRESULT result = SHGetKnownFolderPath(
            FOLDERID_LocalAppData,
            0,
            nullptr,
            &raw_path
        );

        if (FAILED(result)) {
            return Error<DirectoryError>(
                DirectoryError::NotFound,
                "Failed to get user data directory"
            );
        }

        Path path{std::filesystem::path{raw_path}};

        CoTaskMemFree(raw_path);

        return path;
    }

    Result<Path, Error<DirectoryError>> WindowsDirectories::temp() const {
        std::wstring buffer(MAX_PATH, L'\0');

        DWORD length = 0;

        while (true) {
            length = GetTempPathW(
                static_cast<DWORD>(buffer.size()),
                buffer.data()
            );

            if (length == 0) {
                return Error<DirectoryError>(
                    DirectoryError::NotFound,
                    "Failed to get temporary directory"
                );
            }

            // Required size is larger than our buffer
            if (length >= buffer.size()) {
                buffer.resize(buffer.size() * 2);
                continue;
            }

            break;
        }

        buffer.resize(length);

        std::filesystem::path tempPath(buffer);

        // Normalize trailing separators
        tempPath = tempPath.lexically_normal();

        return Path(tempPath);
    }
}
