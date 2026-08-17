/*
    FileBase.cpp

    Implementation of an abstract file object.
*/

#include "platform/FileBase.hpp"

namespace toxico {
    FileBase::FileBase(FileOpenMode open_mode)
        : open_mode_(open_mode) {}

    FileOpenMode FileBase::openMode() const {
        return open_mode_;
    }

    bool FileBase::canRead() const {
        return open_mode_ == FileOpenMode::Read || open_mode_ == FileOpenMode::ReadWrite;
    }

    bool FileBase::canWrite() const {
        return open_mode_ == FileOpenMode::Write || open_mode_ == FileOpenMode::ReadWrite;
    }
}
