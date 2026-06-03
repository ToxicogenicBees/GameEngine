/*
    Scene.hpp

    Declaration for a scene class, in charge of storing game objects
*/

#include "World/Scene.hpp"
#include "World/GameObject.hpp"
#include "Events/EngineEventDispatcher.hpp"
#include <algorithm>
#include <vector>
#include <memory>
#include <iostream>

void Scene::processCreations_() {
    // Add and initialize objects to the scene
    for (auto& obj : pending_create_) {
        obj->scene_ = this;
        obj->init();
        objects_.push_back(std::move(obj));
    }

    // Clear buffer
    pending_create_.clear();
}

void Scene::processDestructions_() {
    // Run destruction logic on objects
    for (auto* obj : pending_destroy_)
        obj->onDestroy();

    // Remove dead objects
    objects_.erase(
        std::remove_if(objects_.begin(), objects_.end(),
            [](const std::unique_ptr<GameObject>& obj) {
                return obj->isDestroyed();
            }),
        objects_.end()
    );

    // Clear buffer
    pending_destroy_.clear();
}

void Scene::init() {
    // Initialize objects
    for (auto& obj : objects_) {
        obj->scene_ = this;
        obj->init();
    }

    // Custom initialization logic
    onInit();
}

void Scene::unload() {
    // Cleanup subscriptions
    for (auto& subscription : subscriptions_)
        EngineEventDispatcher::unsubscribe(std::move(subscription));
    subscriptions_.clear();

    // Custom unload logic
    onUnload();
}

void Scene::flush() {
    processDestructions_();
    processCreations_();
}

Camera& Scene::camera() {
    return camera_;
}

void Scene::destroy(GameObject* obj) {
    // Mark object for destruction
    if (!obj->isDestroyed()) {
        obj->destroy();
        pending_destroy_.push_back(obj);
    }
}
