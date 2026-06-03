/*
    SceneManager.hpp

    Template implementation for a scene manager
*/

#pragma once

#include "World/SceneManager.hpp"
#include <concepts>

template<typename Scene_t, typename... Args>
void SceneManager::loadScene(Args&&... args) {
    pending_ = std::make_unique<Scene_t>(
        context_, std::forward<Args>(args)...
    );
}
