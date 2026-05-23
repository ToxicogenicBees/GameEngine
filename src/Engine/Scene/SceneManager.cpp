/*
    SceneManager.hpp

    Implementation for a scene manager
*/

#include "Scene/SceneManager.hpp"
#include "Rendering/Window.hpp"

SceneManager::SceneManager(EngineContext& context)
    : context_(context) {}

void SceneManager::render(Renderer& renderer) {
    if (active_)
        active_->render(renderer);
}

void SceneManager::update(double dt) {
    if (active_)
        active_->update(dt);

    processSceneChange_();
}

void SceneManager::processSceneChange_() {
    if (!pending_)
        return;

    if (active_)
        active_->unload();

    active_ = std::move(pending_);
    pending_ = nullptr;

    active_->init();
}
