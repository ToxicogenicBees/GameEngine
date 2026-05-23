/*
    EngineAPI.cpp

    Implementation for a safe engine wrapper for applications
*/

#include "Core/EngineAPI.hpp"

EngineAPI::EngineAPI(Engine& engine)
    : engine_(engine) {}

InputManager& EngineAPI::input() const {
    return engine_.input_;
}

Size EngineAPI::size() const {
    return engine_.window_.size();
}

size_t EngineAPI::width() const {
    return engine_.window_.width();
}

size_t EngineAPI::height() const {
    return engine_.window_.height();
}
