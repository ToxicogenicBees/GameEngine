/*
    EngineContext.hpp

    Declaration for an engine context struct
*/

#pragma once

class AssetManager;
class InputManager;
class Renderer;

class EngineContext {
private:
    AssetManager& assets_;
    InputManager& input_;
    Renderer& renderer_;

public:
    /**
     * @brief Constructor
     * 
     * @param assets A reference to an asset manager
     * @param input A reference to an input manager
     * @param renderer A reference to a renderer
     */
    EngineContext(AssetManager& assets, InputManager& input, Renderer& renderer);

    /**
     * @brief Fetch an asset manager
     * 
     * @return A reference to the asset manager
     */
    AssetManager& assets();

    /**
     * @brief Fetch an input manager
     * 
     * @return A reference to the input manager
     */
    InputManager& input();

    /**
     * @brief Fetch a renderer
     * 
     * @return A reference to the renderer
     */
    Renderer& renderer();
};
