/*
    GameObject.hpp

    Declaration for a game object that can be rendered on the screen
*/

#pragma once

#include "Core/ILifecycle.hpp"
#include "Core/Entity.hpp"
#include "GameObject/Component.hpp"
#include "Rendering/Window.hpp"
#include "Types/Transform.hpp"
#include "Types/Size.hpp"
#include <filesystem>
#include <memory>

class Scene; // forward declaration

class GameObject : public Entity, public ILifecycle {
private:
    std::vector<std::unique_ptr<Component>> components_;
    Scene* scene_ = nullptr;

protected:
    friend class Scene;

public:
    /**
     * @brief Constructor
     */
    GameObject() = default;

    /**
     * @brief Initialize the object
     */
    void init() final;

    /**
     * @brief Update the object
     * 
     * @param dt Time between updates
     */
    void update(double dt) final;

    /**
     * @brief Render the object
     */
    void render(Camera& camera) final;

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

#include "GameObject/GameObject.tpp"
