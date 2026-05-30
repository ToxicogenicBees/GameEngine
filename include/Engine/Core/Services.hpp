/*
    Services.hpp

    Declaration of a global class containing a pointer to all important engine services
*/

#pragma once

#include "Assets/AssetManager.hpp"
#include "Resources/ResourceManager.hpp"
#include "World/SceneManager.hpp"
#include "Input/InputManager.hpp"
#include "Rendering/Renderer.hpp"
#include "Rendering/Window.hpp"

class Services {
private:
    static inline AssetManager* assets_ = nullptr;
    static inline ResourceManager* resources_ = nullptr;
    static inline SceneManager* scenes_ = nullptr;
    static inline InputManager* input_ = nullptr;
    static inline Renderer* renderer_ = nullptr;
    static inline Window* window_ = nullptr;

protected:
    friend class Engine;

    /**
     * @brief Sets the pointer to the asset manager.
     * 
     * @param assets A pointer to the asset manager.
     */
    static void setAssets(AssetManager* assets);

    /**
     * @brief Sets the pointer to the resources manager.
     * 
     * @param assets A pointer to the resources manager.
     */
    static void setResources(ResourceManager* resources);

    /**
     * @brief Sets the pointer to the input manager.
     * 
     * @param input A pointer to the input manager.
     */
    static void setInput(InputManager* input);

    /**
     * @brief Sets the pointer to the renderer.
     * 
     * @param renderer A pointer to the renderer.
     */
    static void setRenderer(Renderer* renderer);

    /**
     * @brief Sets the pointer to the window.
     * 
     * @param window A pointer to the window.
     */
    static void setWindow(Window* window);

    /**
     * @brief Sets the pointer to the scene manager.
     * 
     * @param scenes A pointer to the scene manager.
     */
    static void setScenes(SceneManager* scenes);

public:
    /**
     * @brief Gets a pointer to the asset manager.
     * 
     * @return A pointer to the asset manager.
     */
    static AssetManager* assets();

    /**
     * @brief Gets a pointer to the resources manager.
     * 
     * @return A pointer to the resources manager.
     */
    static ResourceManager* resources();

    /**
     * @brief Gets a pointer to the input manager.
     * 
     * @return A pointer to the input manager.
     */
    static InputManager* input();

    /**
     * @brief Gets a pointer to the renderer.
     * 
     * @return A pointer to the renderer.
     */
    static Renderer* renderer();

    /**
     * @brief Gets a pointer to the window.
     * 
     * @return A pointer to the window.
     */
    static Window* window();

    /**
     * @brief Gets a pointer to the scene manager.
     * 
     * @return A pointer to the scene manager.
     */
    static SceneManager* scenes();
};
