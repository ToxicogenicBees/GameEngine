/*
    Scene.hpp

    Declaration for a scene class, in charge of storing game objects
*/

#include "Game/Scene.hpp"
#include "Game/GameObjects/GameObject.hpp"
#include <algorithm>
#include <vector>
#include <memory>

/**
 * @brief Remove all destroyed objects from the scene
 */
void Scene::processDestructions() {
    for (auto* obj : pending_destroy_)
        obj->onDestroy();

    objects_.erase(
        std::remove_if(objects_.begin(), objects_.end(),
            [](const std::unique_ptr<GameObject>& obj) {
                return !obj->alive_;
            }),
        objects_.end()
    );

    pending_destroy_.clear();
}

/**
 * @brief Initialize the scene and its objects
 */
void Scene::init() {
    for (auto& obj : objects_)
        obj->init();
}

/**
 * @brief Update the scene and its objects
 * 
 * @param dt The time difference since the last update
 */
void Scene::update(float dt) {
    for (auto& obj : objects_)
        obj->update(dt);

    processDestructions();
}

/**
 * @brief Logic to draw the scene and it's object to a window
 * 
 * @param window The window the object is being drawn to
 */
void Scene::render(Window& window) {
    for (auto& obj : objects_)
        obj->render(window);
}

/**
 * @brief Remove a game object from the scene.
 * 
 * @param object The object being removed
 */
void Scene::destroy(GameObject* obj) {
    obj->alive_ = false;
    pending_destroy_.push_back(obj);
}
