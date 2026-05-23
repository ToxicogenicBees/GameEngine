/*
    EngineContext.cpp

    Implementation for an engine context struct
*/

#include "Core/EngineContext.hpp"
#include "Assets/AssetManager.hpp"
#include "Input/InputManager.hpp"
#include "Rendering/Renderer.hpp"

EngineContext::EngineContext(AssetManager& assets, InputManager& input, Renderer& renderer)
    : assets_(assets), input_(input), renderer_(renderer) {}

AssetManager& EngineContext::assets() {
    return assets_;
}

InputManager& EngineContext::input() {
    return input_;
}

Renderer& EngineContext::renderer() {
    return renderer_;
}
