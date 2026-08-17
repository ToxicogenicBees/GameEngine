/*
    Platform.tpp

    Template implementation of the operating-system engine layer.
*/

#pragma once

#include "platform/Platform.hpp"

namespace toxico {
    template<typename Interface, typename Implementation>
    void Platform::addModule(std::unique_ptr<Implementation> module) {
        modules_.add<Interface>(std::move(module));
    };
}
