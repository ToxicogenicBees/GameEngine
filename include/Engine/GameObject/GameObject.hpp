/*
    GameObject.hpp

    Declaration for a game object that can be rendered on the screen
*/

#pragma once

#include "GameObject/Component.hpp"
#include "Core/ILifecycle.hpp"
#include "Rendering/Window.hpp"
#include "Types/Vector2.hpp"
#include "Types/Size.hpp"
#include <filesystem>
#include <memory>

class Scene; // forward declaration

class GameObject : public ILifecycle {
private:
    std::vector<std::unique_ptr<Component>> components_;
    Scene* scene_ = nullptr;
    bool alive_ = true;

protected:
    friend class Scene;

public:
    Vector2 position = Vector2::zero();

    /**
     * @brief Constructor
     */
    GameObject() = default;

    /**
     * @brief Initialize the object
     */
    void init() override {}

    /**
     * @brief Update the object
     * 
     * @param dt Time between updates
     */
    void update(double dt) override {}

    /**
     * @brief Render the object
     */
    void render() override;

    /**
     * @brief Logic to handle removing the object from a scene.
     */
    virtual void onDestroy() {}

    /**
     * @brief Gets if the game object is alive.
     * 
     * @return True if the game object is alive, false otherwise.
     */
    bool isAlive() const;

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
