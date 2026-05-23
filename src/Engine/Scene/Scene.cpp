/*
    Scene.hpp

    Declaration for a scene class, in charge of storing game objects
*/

#include "Scene/Scene.hpp"
#include "GameObject/GameObject.hpp"
#include "Events/EngineEventDispatcher.hpp"
#include <algorithm>
#include <vector>
#include <memory>

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
                return !obj->alive_;
            }),
        objects_.end()
    );

    // Clear buffer
    pending_destroy_.clear();
}

Scene::Scene(EngineContext& context)
    : context_(context) {}

void Scene::init() {
    // Custom initialization logic
    onInit();

    // Initialize objects
    for (auto& obj : objects_)
        obj->init();
}

void Scene::update(double dt) {
    // Add created objects to the scene
    processCreations_();

    // Update objects
    for (auto& obj : objects_) {
        if (obj->isAlive())
            obj->update(dt);
    }

    // Custom update logic
    onUpdate(dt);

    // Remove destroyed objects from the scene
    processDestructions_();
}

void Scene::render(Renderer& renderer) {
    // Render all objects
    for (auto& obj : objects_)
        obj->render(renderer);
    
    // Custom render logic
    onRender();
}

void Scene::unload() {
    // Cleanup subscriptions
    for (auto& sub : subscriptions_)
        EngineEventDispatcher::unsubscribe(sub);
    subscriptions_.clear();

    // Custom unload logic
    onUnload();
}

void Scene::destroy(GameObject* obj) {
    // Mark object for destruction
    if (obj->alive_) {
        obj->alive_ = false;
        pending_destroy_.push_back(obj);
    }
}

EngineContext& Scene::context() {
    return context_;
}
