/*
    Path.hpp

    Declaration of a file path class.
*/

#pragma once

#include <filesystem>
#include <functional>
#include <string>
#include <ostream>

namespace toxico {
    class Path {
    private:
        std::filesystem::path path_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param path The desired filepath.
         */
        Path(const std::filesystem::path& path);

        /**
         * @brief Comparision operator.
         * 
         * @param other Another path object.
         * @return If the two path are the same.
         */
        bool operator==(const Path& other) const = default;

        /**
         * @brief Gets if the filepath is empty.
         * 
         * @return If the filepath is empty.
         */
        bool empty() const;

        /**
         * @brief Gets the parent directory of this path.
         * 
         * @return The parent directory of this path.
         */
        Path parent() const;

        /**
         * @brief Gets the file name of this path.
         * 
         * @return The file name of this path.
         */
        std::filesystem::path filename() const;

        /**
         * @brief Gets the file extension of this path.
         * 
         * @return The file exdtension of this path.
         */
        std::filesystem::path extension() const;

        /**
         * @brief Gets the stem of this path.
         * 
         * @return The stem of this path.
         */
        std::filesystem::path stem() const;

        /**
         * @brief Gets if this path has a parent.
         * 
         * @return If this path has a parent.
         */
        bool hasParent() const;

        /**
         * @brief Gets if this path has an extension.
         * 
         * @return If this path has an extension.
         */
        bool hasExtension() const;

        /**
         * @brief Gets if this path is absolute.
         * 
         * @return If this path is absolute.
         */
        bool isAbsolute() const;

        /**
         * @brief Gets if this path is relative.
         * 
         * @return If this path is relative.
         */
        bool isRelative() const;

        /**
         * @brief Gets the native file path object.
         * 
         * @return The native file path object.
         */
        const std::filesystem::path& native() const;

        /**
         * @brief Gets the full path as a string.
         * 
         * @return The full path as a string.
         */
        std::string string() const;

        /**
         * @brief Gets the full path as a wstring.
         * 
         * @return The full path as a wstring.
         */
        std::wstring wstring() const;

        /**
         * @brief Combines two paths.
         * 
         * @param other The path being attached to this one.
         * @result The combined path.
         */
        Path operator/(const Path& other) const;

        /**
         * @brief Combines a path to this path.
         * 
         * @param other The path being attached to this one.
         * @return A reference to this path object.
         */
        Path& operator/=(const Path& other);
    };

    /**
     * @brief Overloaded insertion operator
     * 
     * @param o A reference to an output stream
     * @param path The path being output to the stream
     * 
     * @result A reference to the output stream being output to
     */
    std::ostream& operator<<(std::ostream& o, const Path& path);
}

namespace std {
    template<>
    struct hash<toxico::Path> {
        /**
         * @brief Calculate a hash for a path object.
         * 
         * @param path A path object.
         * @return A deterministic hash for the path object.
         */
        std::size_t operator()(const toxico::Path& path) const noexcept;
    };
}
