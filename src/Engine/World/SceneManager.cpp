/*
    SceneManager.hpp

    Implementation for a scene manager
*/

#include "World/SceneManager.hpp"

void SceneManager::processSceneChange() {
    if (!pending_)
        return;

    if (active_)
        active_->unload();

    active_ = std::move(pending_);
    pending_ = nullptr;

    active_->init();
}

void SceneManager::flushScene() {
    if (active_)
        active_->flush();
}