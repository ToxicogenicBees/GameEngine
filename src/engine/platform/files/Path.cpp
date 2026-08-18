/*
    Path.cpp

    Implementation of a file path class.
*/

#include "platform/files/Path.hpp"

namespace toxico {
    Path::Path(const std::filesystem::path& path)
        : path_(path)
    {
        if (path_.filename().empty() && !path_.empty())
            path_ = path_.parent_path();
    }

    bool Path::empty() const {
        return path_.empty();
    }

    Path Path::parent() const {
        return path_.parent_path();
    }

    std::filesystem::path Path::filename() const {
        return path_.filename();
    }

    std::filesystem::path Path::extension() const {
        return path_.extension();
    }

    std::filesystem::path Path::stem() const {
        return path_.stem();
    }

    bool Path::hasParent() const {
        return path_.has_parent_path();
    }

    bool Path::hasExtension() const {
        return path_.has_extension();
    }

    bool Path::isAbsolute() const {
        return path_.is_absolute();
    }

    bool Path::isRelative() const {
        return path_.is_relative();
    }

    const std::filesystem::path& Path::native() const {
        return path_;
    }

    std::string Path::string() const {
        return path_.string();
    }

    std::wstring Path::wstring() const {
        return path_.wstring();
    }

    Path Path::operator/(const Path& other) const {
        return path_ / other.path_;
    }

    Path& Path::operator/=(const Path& other) {
        path_ /= other.path_;
        return *this;
    }

    std::ostream& operator<<(std::ostream& o, const Path& path) {
        o << path.native();
        return o;
    }
}

namespace std {
    size_t hash<toxico::Path>::operator()(const toxico::Path& path) const noexcept {
        return hash<std::filesystem::path>{}(path.native());
    }
}
