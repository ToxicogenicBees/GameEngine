/*
    EngineAPI.hpp

    Declaration for a safe engine wrapper for applications
*/

#pragma once

#include "Input/InputManager.hpp"
#include "Core/Engine.hpp"
#include "Types/Size.hpp"

class EngineAPI {
private:
    Engine& engine_;

public:
    /**
     * @brief Constructor
     * 
     * @param engine A reference to the engine
     */
    EngineAPI(Engine& engine);

    /**
     * @brief Start a scene transition
     * 
     * @param args Constructor arguments for the new scene
     */
    template<typename T, typename... Args>
    void setScene(Args&&... args);

    /**
     * @brief Gets the input service for this engine
     * 
     * @return The input service for this engine
     */
    InputManager& input() const;

    /**
     * @brief Gets the size of the window.
     * 
     * @return The size of the window.
     */
    Size size() const;

    /**
     * @brief Gets the width of the window.
     * 
     * @return The width of the window.
     */
    size_t width() const;

    /**
     * @brief Gets the height of the window.
     * 
     * @return The height of the window.
     */
    size_t height() const;
};

#include "Core/EngineAPI.tpp"
