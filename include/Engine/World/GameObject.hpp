/*
    GameObject.hpp

    Declaration for a game object that can be rendered on the screen
*/

#pragma once

#include "Core/Entity.hpp"
#include "Components/Component.hpp"
#include "Rendering/Window.hpp"
#include "Math/Transform.hpp"
#include <filesystem>
#include <memory>

class Scene; // forward declaration

class GameObject : public Entity {
private:
    std::vector<std::unique_ptr<Component>> components_;
    Scene* scene_ = nullptr;

protected:
    friend class Scene;

    /**
     * @brief Custom initialization logic.
     */
    virtual void onInit() {}

public:
    /**
     * @brief Constructor
     */
    GameObject() = default;

    /**
     * @brief Initialize the object
     */
    void init();

    /**
     * @brief Gets the pointer to this game object's scene.
     * 
     * @return A pointer to this game object's scene.
     */
    Scene* scene() const;

    /**
     * @brief Add a component to the game object
     * 
     * @param args Component constructor arguments
     * @return The component created
     */
    template<typename Component_t, typename... Args>
    Component_t* addComponent(Args&&... args);

    /**
     * @brief Gets the component of a specific type for this game object
     * 
     * @return A pointer to the component, or nullptr if it doesn't exist
     */
    template<typename Component_t>
    Component_t* getComponent();
};

#include "World/GameObject.tpp"
