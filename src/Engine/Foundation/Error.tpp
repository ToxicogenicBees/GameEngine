/*
    Error.tpp

    Template implementation of an error class.
*/

#pragma once

#include "Foundation/Error.hpp"

namespace toxico {
    template<typename Code>
    requires std::is_enum_v<Code>
    Error<Code>::Error(Code code, std::string message)
        : message_(std::move(message)),
          code_(code)
    {}

    template<typename Code>
    requires std::is_enum_v<Code>
    Error<Code>::Error(Code code)
        : code_(code) {}

    template<typename Code>
    requires std::is_enum_v<Code>
    Error<Code>& Error<Code>::addContext(std::string context) {
        context_.insert(context_.begin(), std::move(context));
        return *this;
    }

    template<typename Code>
    requires std::is_enum_v<Code>
    const std::vector<std::string>& Error<Code>::context() const {
        return context_;
    }

    template<typename Code>
    requires std::is_enum_v<Code>
    Code Error<Code>::code() const {
        return code_;
    }

    template<typename Code>
    requires std::is_enum_v<Code>
    const std::string& Error<Code>::what() const {
        return message_;
    }

    template<typename Code>
    requires std::is_enum_v<Code>
    Error<Code>::operator bool() const {
        return code_ == Code::None;
    }
}
