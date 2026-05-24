/*
    SceneManager.hpp

    Implementation for a scene manager
*/

#include "Scene/SceneManager.hpp"
#include "Rendering/Window.hpp"

void SceneManager::render() {
    if (active_)
        active_->render();
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
