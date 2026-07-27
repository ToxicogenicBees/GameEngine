/*
    Platform.cpp

    Implementation of the operating-system engine layer.
*/

#include "Platform/Platform.hpp"

namespace toxico {
    IFileSystem& Platform::files() {
        return modules_.get<IFileSystem>();
    }

    IClipboard& Platform::clipboard() {
        return modules_.get<IClipboard>();
    }
    
    IPlatformDirectories& Platform::dirs() {
        return modules_.get<IPlatformDirectories>();
    }
}
