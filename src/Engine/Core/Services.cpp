/*
    Services.cpp

    Template implementation of a global class containing a pointer to all important engine services
*/

#include "Core/Services.hpp"

void Services::setAssets(AssetManager* assets) {
    assets_ = assets;
}

void Services::setResources(ResourceManager* resources) {
    resources_ = resources;
}

void Services::setInput(InputManager* input) {
    input_ = input;
}

void Services::setRenderer(Renderer* renderer) {
    renderer_ = renderer;
}

void Services::setWindow(Window* window) {
    window_ = window;
}

void Services::setScenes(SceneManager* scenes) {
    scenes_ = scenes;
}

AssetManager* Services::assets() {
    return assets_;
}

ResourceManager* Services::resources() {
    return resources_;
}

InputManager* Services::input() {
    return input_;
}

Renderer* Services::renderer() {
    return renderer_;
}

Window* Services::window() {
    return window_;
}

SceneManager* Services::scenes() {
    return scenes_;
}
