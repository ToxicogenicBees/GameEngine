/*
    ClipboardBase.cpp

    Implementation of a base abstract clipboard.
*/

#include "Platform/ClipboardBase.hpp"

namespace toxico {
    void ClipboardBase::setFormat(ClipboardFormat format) {
        format_ = format;
    }

    ClipboardFormat ClipboardBase::format() const {
        return format_;
    }
}
