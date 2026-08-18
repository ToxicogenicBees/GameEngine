/*
    Platform.cpp

    Implementation of the operating-system engine layer.
*/

#include "platform/Platform.hpp"

namespace toxico {
    IFileSystem& Platform::files() {
        return modules_.get<IFileSystem>();
    }

    IClipboard& Platform::clipboard() {
        return modules_.get<IClipboard>();
    }
    
    IDirectories& Platform::dirs() {
        return modules_.get<IDirectories>();
    }
}
